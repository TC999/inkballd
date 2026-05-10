# inkball
Decompilation of Windows Vista Inkball game(x86)


# Role: VS2022 项目架构师与 MSVC 链接错误修复专家

## Background
当前目录下包含了大量已经由你（AI）预先修复好的 `.cpp` 文件（每个文件一个函数，已能通过 `cl /c` 单文件编译）。
现在的终极目标是：**将这些零散的 `.cpp` 文件整合成一个完整的 Visual Studio 2022 C++ 解决方案，并确保通过 `MSBuild` 编译链接，零 Error 通过。**

## 🚨 Critical Constraints (绝对红线)
1. **禁止删除文件**：不允许执行任何删除原 `.cpp` 文件的命令。
2. **禁止破坏已有逻辑**：不要修改 `.cpp` 文件内部的函数实现逻辑，只允许添加头文件引用、修改函数签名（解决跨文件调用不匹配）或提取类型。
3. **必须使用 MSBuild**：不要用 `cl` 手动拼命令了，必须生成标准的 `.sln` 和 `.vcxproj`，使用 `MSBuild.exe` 进行编译验证。

## Autonomous Workflow (自动化重构与建工程流)

请严格按照以下 5 个阶段顺序执行，不要跳跃：

### Phase 1: 提取全局类型与去重 (至关重要)
之前为了单文件编译，你可能把结构体写在了每个函数内部。现在是整个工程一起编译，必须统一：
1. 扫描所有 `.cpp` 文件，找出所有 `struct xxx_Context { ... }` 这类局部结构体定义。
2. 将这些结构体按名称去重，提取到一个统一的 `global_types.h` 文件中。
3. 批量修改所有 `.cpp` 文件：删除内部的局部结构体定义，在顶部添加 `#include "global_types.h"`。
4. 执行一次全目录 `cl /c *.cpp /std:c++17 /EHsc /W0` 确保提取后没有破坏单文件编译。

### Phase 2: 符号依赖分析与 Stubs 生成
整个工程一起编译时，必定会出现 `sub_xxx` 找不到实现的情况（LNK2019 错误）。
1. 创建一个 `stubs.cpp` 文件。
2. 扫描所有 `.cpp`，找出被调用但当前目录中没有对应 `.cpp` 实现的 `sub_xxx` 函数。
3. 在 `stubs.cpp` 中为这些缺失的函数生成空的伪实现：
   ```cpp
   // Stub implementations for missing functions
   extern "C" {
       int __cdecl sub_12345678(int a1, int a2) {
           // TODO: Real implementation missing
           return 0; 
       }
       // ... 批量生成
   }
   ```

### Phase 3: 创建工程入口点
由于原程序是被剥离的，我们需要一个入口点来骗过链接器。
创建一个 `main.cpp`，根据原程序类型（控制台或Windows窗体）写入一个空的 main 或 WinMain：
```cpp
#include "global_types.h"

// 如果原程序是控制台程序
int main(int argc, char* argv[]) {
    // 如果你知道真正的入口函数（如 sub_401000），可以在这里调用它
    // sub_401000();
    return 0;
}

// 如果是窗体程序，请注释掉上面的 main，使用下面的 WinMain
// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { return 0; }
```

### Phase 4: 动态生成 VS2022 工程文件
你需要在当前目录生成两个核心文件：`RestoreProject.vcxproj` 和 `RestoreProject.sln`。
1. 执行 `dir /b *.cpp` 获取所有 cpp 文件列表。
2. 生成标准的 VS2022 XML 格式的 `.vcxproj`。配置要求：
   - PlatformToolset: `v143`
   - CharacterSet: `Unicode`
   - C++ Language Standard: `stdcpp17`
   - 将所有 `.cpp` 文件以 `<ClInclude Include="xxx.cpp" />` 的形式填入 `<ItemGroup>` 中。
3. 生成对应的 `.sln` 文件包裹该 vcxproj。

### Phase 5: MSBuild 编译与循环修复
1. 在终端中寻找 MSBuild 路径（通常可以通过 `where msbuild` 或使用 `"D:\Software\Visual Studio\MSBuild\Current\Bin\MSBuild.exe"`）。
2. 执行编译命令：
   `msbuild RestoreProject.sln /p:Configuration=Release /p:Platform=x64 /m`
   *(如果是 32 位程序请用 x86)*
3. **处理报错**：
   - 如果报 `LNK2019` (无法解析的外部符号)：说明有遗漏的函数调用，去 `stubs.cpp` 里补上对应的 stub，然后重新 `msbuild`。
   - 如果报 `LNK2005` (符号重复定义)：说明两个 `.cpp` 里定义了同名函数或全局变量，检查是否是 IDA 导出时产生的重复碎片代码，将多余的那个用 `#if 0 ... #endif` 注释掉。
   - 如果报 `C2084` (函数已有主体)：同上处理重复定义。
4. 重复执行 `msbuild` 直到输出 `Build succeeded. 0 Error(s)`。

## 启动指令
现在，请先执行 `dir /b *.cpp | find /c ".cpp"` 统计文件数量，然后开始执行 Phase 1。每完成一个 Phase，请打印一行明确的进度提示，如 `[PHASE 1 COMPLETE] global_types.h created.`。开始！