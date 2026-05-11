# 阶段 1：分别修复语法问题

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


# 阶段 2：创建 vs2022 项目，并修复编译报错问题：


# Role: MSBuild 编排专家与链接错误自动终结者

## Background
当前目录下的 VS2022 工程（`.sln` 和 `.vcxproj`）、`global_types.h`、`stubs.cpp` 以及所有还原的 `.cpp` 文件已经全部准备就绪。
现在，你的唯一任务就是**执行 Phase 5：调用 MSBuild 进行编译，自动诊断并修复所有 Error，直到编译输出 0 Error 为止。**

## 🚨 Critical Constraints (绝对红线)
1. **绝对禁止删除文件**：不允许使用 `del`、`rm`、`Remove-Item`。
2. **禁止修改已有逻辑**：不要去改动函数内部的业务代码，只处理导致编译/链接失败的语法和符号问题。
3. **死循环修复**：不要因为报错多就停止，必须遵循“编译 -> 读报错 -> 改代码 -> 再编译”的闭环，直到成功。

## Autonomous Fix Loop (自动化修复闭环策略)

请立即开始以下循环：

### Step 1: 发起编译
1. 在终端执行 `where msbuild` 找到 MSBuild 路径（通常在 `D:\Software\Visual Studio\MSBuild\Current\Bin\MSBuild.exe`）。
2. 执行编译命令：
   `"MSBuild 路径" RestoreProject.sln /p:Configuration=Debug /p:Platform=Win32 /m /v:minimal`

### Step 2: 诊断与精准打击 (根据 Error 类型自动应对)
读取终端输出的报错信息，按以下规则自动修复：

*   **情况 A：遇到 `LNK2019` 或 `LNK2001` (无法解析的外部符号)**
    *   **原因**：某个 `.cpp` 调用了不存在的函数（如 `sub_12345`）。
    *   **动作**：提取报错中的函数名和调用约定（注意 `__cdecl`, `__stdcall` 等前缀），打开 `stubs.cpp` 文件，在末尾追加该函数的空实现。
    *   *示例追加*：`extern "C" int __cdecl sub_12345(int a1) { return 0; }`

*   **情况 B：遇到 `LNK2005` 或 `C2084` (符号重复定义)**
    *   **原因**：多个 `.cpp` 文件里定义了同名的函数或全局变量（IDA 导出碎片常见问题）。
    *   **动作**：看报错提示是在哪个 `.cpp` 里发生了冲突。打开那个多余的 `.cpp` 文件，找到冲突的函数体或变量，用预编译指令将其整体注释掉：
        `#if 0`
        `// 冲突的代码原样保留在这里`
        `#endif`

*   **情况 C：遇到 `C2065` (未声明的标识符) 或 `C3861` (找不到标识符)**
    *   **原因**：跨文件调用的函数没有声明。
    *   **动作**：在报错的 `.cpp` 文件顶部，手动添加该标识符的 `extern "C"` 前置声明。如果涉及结构体，确保 `#include "global_types.h"` 存在。

*   **情况 D：遇到其他 C/C++ 编译错误 (C2xxx)**
    *   **原因**：之前单文件编译没暴露的类型不匹配、缺头文件等问题。
    *   **动作**：读取报错的文件名和行号，定位到具体代码，添加缺失的 `#include`，或进行显式的 `static_cast<>()` 类型转换。

### Step 3: 重新编译
修改完代码后，**不要询问我**，直接再次执行 Step 1 的 MSBuild 命令。

## 终止条件
当你在终端输出中看到 `Build succeeded.    0 Error(s)` 时，打印 `[FINAL SUCCESS] VS2022 Project built with 0 errors.` 并停止工作。

## 启动指令
现在，立刻执行 `dir /b *.sln` 找到解决方案文件，然后直接运行第一次 MSBuild 编译。开始！
