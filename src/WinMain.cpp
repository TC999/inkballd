#include "global_types.h"
#include <windows.h>
#include <cstdint>
#include <cstdio>
#include <cwchar>
#include <ctime>
#include <CommCtrl.h>
#include <float.h>
#include <new.h>
#pragma comment(lib, "Comctl32.lib")

extern "C" {
    int snwprintf(wchar_t* buffer, size_t count, const wchar_t* format, ...);
    long wtol(const wchar_t* str);

    extern int __stdcall CanRunInkball(int* result);
    extern void __stdcall DispError(HWND hWnd, HINSTANCE hInstance, HINSTANCE hPrevInstance);
    extern int __stdcall WinSqmIsOptedIn();
    extern void __stdcall _WinSqmDWORDEvent(void* param1, int param2, int param3, int param4);
    extern DWORD __stdcall InkBallRecovery(void* param1);
    extern int __stdcall EnableClassicWispWithPtr(LPVOID* ptr);
    extern int __stdcall WinInit(HINSTANCE hInstance, int nCmdShow, HWND* hWnd, HACCEL* hAccel);
    extern void* __cdecl new_oom_handler(unsigned int size);
    extern void __stdcall ExitBadCommandLine(HWND hWnd);
    extern void __stdcall SetMenuChecks(HWND hWnd);
    extern uint32_t dword_10B2704;
    void __stdcall WPP_INIT_CONTROL_ARRAY(void* control_array);
    uint32_t __stdcall WppInitUm(int unused_param);
    void __stdcall WppCleanupUm();
}

int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    HRESULT result;
    HRESULT coinit_result;
    WPARAM wParam;
    HRESULT create_result;
    void* game_manager_ptr;
    CGameManager* game_manager;
    uint32_t difficulty;
    WCHAR first_char;
    uint16_t* file_path;
    uint16_t* file_path_end;
    char last_error;
    int* unused_ptr;
    tagMSG msg;
    uint8_t log_buffer[8];
    LARGE_INTEGER due_time;
    void* com_ptr;
    HACCEL accel_table;
    int com_initialized;
    LPVOID wisp_ptr;
    HANDLE timer_handle;
    int init_step;

    // ==================== WPP Tracing 初始化 ====================
    WPP_INIT_CONTROL_ARRAY(&WPP_MAIN_CB);
    WPP_REGISTRATION_GUIDS = WPP_ThisDir_CTLGUID_ControlGuid;
    dword_10B2704 = (int)WPP_ThisDir_CTLGUID_MobTabPerfTraceProvider;
    WPP_GLOBAL_Control = reinterpret_cast<uint64_t>(&WPP_MAIN_CB);
    WppInitUm((int)L"TabletPC\\InkBall");

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "wWinMain", 0);
    init_step = 0;

    HeapSetInformation(0, HeapEnableTerminationOnCorruption, 0, 0);
    com_initialized = 0;

    // [保留] CanRunInkball 已在之前被注释掉

    if (WinSqmIsOptedIn())
        _WinSqmDWORDEvent(&SQM_INCREMENT_DWORD, 0, 157, 1);

    SetProcessDPIAware();

    result = RegisterApplicationRestart(L" ", 0);
    if (result < 0 && WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
        ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
        WPP_SF_d(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0xCu, &stru_1003520, result);

    coinit_result = RegisterApplicationRecoveryCallback(InkBallRecovery, 0, 0, 0);
    if (coinit_result < 0 && WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
        ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
        WPP_SF_d(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0xDu, &stru_1003520, coinit_result);

    wParam = -1;
    wisp_ptr = 0;
    timer_handle = 0;

    create_result = CoInitialize(0);
    com_initialized = create_result >= 0;

    if (create_result < 0)
    {
        if (WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
            ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
            WPP_SF_d(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0xEu, &stru_1003520, create_result);
        goto LABEL_CLEANUP;
    }

    // =====================================================================
    // 【修改点1】绕过 EnableClassicWispWithPtr
    //
    // 原逻辑：调用 EnableClassicWispWithPtr 初始化 WISP 手写笔子系统，
    //         失败则直接落到 DispError 弹窗。
    //
    // 问题：现代系统（Win10/11、非触屏环境）大概率缺少 Tablet PC 的
    //       COM 组件注册，导致该函数失败。
    //
    // 修复：尝试调用，失败时不阻断，仅记录日志后继续。
    //       wisp_ptr 为 NULL 时，清理代码已通过 if(wisp_ptr) 保护，
    //       不会崩溃。
    // =====================================================================
    {
        int wisp_result = EnableClassicWispWithPtr(&wisp_ptr);
        if (!wisp_result)
        {
            // WISP 初始化失败 —— 记录日志但不阻断
            if (WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
                ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
            {
                WPP_SF_(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0xFu, &stru_1003520);
            }
            wisp_ptr = NULL;  // 确保为 NULL，清理时安全跳过
        }
    }

    // =====================================================================
    // 以下为正常初始化流程（原 EnableClassicWispWithPtr 成功分支内的全部内容）
    // =====================================================================
    g_hInst = hInstance;

    if (WinInit(hInstance, nShowCmd, reinterpret_cast<HWND*>(&hInstance), &accel_table) < 0)
        goto LABEL_CLEANUP;

    _set_new_handler(reinterpret_cast<_PNH>(new_oom_handler));
    init_step = 1;

    game_manager_ptr = operator new(0x14u);
    com_ptr = game_manager_ptr;
    init_step = 2;

    if (game_manager_ptr)
        game_manager = (CGameManager*)CGameManager_ctor(game_manager_ptr, (HWND)hInstance);
    else
        game_manager = 0;

    g_pCGameManager = game_manager;
    init_step = 0;

    // =====================================================================
    // 【修改点2】CGameManager_Init 失败时记录返回值，便于排查
    // =====================================================================
    if (CGameManager_Init(game_manager) < 0)
    {
        // Init 失败，记录 trace 后弹窗（保留此路径的错误提示）
        if (WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
            ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
        {
            WPP_SF_(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0x11u, &stru_1003520);
        }
        // 如果 CGameManager_Init 仍然失败，可以在此处加 OutputDebugString 排查
        // OutputDebugStringA("[wWinMain] CGameManager_Init FAILED\n");
        goto LABEL_DISPERROR;  // 此路径保留弹窗，因为游戏核心初始化失败确实需要提示
    }

    difficulty = CRegistryManager::ReadDifficulty((CRegistryManager*)&g_CRegistryManager);
    CBoardManager::SetDifficulty((CBoardManager*)&g_CBoardManager, difficulty);

    if (!*lpCmdLine)
        goto LABEL_LOAD_RANDOM;

    if (*lpCmdLine == 47)  // '/'
    {
        first_char = lpCmdLine[1];
        if (first_char == 114 || first_char == 82)  // 'r' or 'R'
        {
            if (lpCmdLine[2] != 58)  // ':'
                ExitBadCommandLine((HWND)hInstance);

            file_path = reinterpret_cast<uint16_t*>(lpCmdLine + 3);
            if (lpCmdLine[3] == 34)  // '"'
                file_path = reinterpret_cast<uint16_t*>(lpCmdLine + 4);

            file_path_end = &file_path[wcslen(reinterpret_cast<const wchar_t*>(file_path)) - 1];
            if (*file_path_end == 34)  // '"'
                *file_path_end = 0;

            if (!CBoardManager::LoadBoardFromResources(
                (CBoardManager*)&g_CBoardManager,
                (const wchar_t*)file_path,
                &BoardData,
                &iBoardSizeBytes))
            {
            LABEL_LOAD_RANDOM:
                CBoardManager::LoadRandomBoardFromResources(
                    (CBoardManager*)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
            }
        }
    }

    if (g_pCGameManager)
    {
        CGameManager_LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
        *reinterpret_cast<uint32_t*>(g_pCGameManager) = 1;
    }

    SetMenuChecks((HWND)hInstance);

    timer_handle = CreateWaitableTimerW(0, 0, 0);
    if (!timer_handle &&
        WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
        ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0)
    {
        last_error = GetLastError();
        WPP_SF_d(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0x12u, &stru_1003520, last_error);
    }

    due_time.QuadPart = -150000;
    SetWaitableTimer(timer_handle, &due_time, 0, 0, 0, 0);

    ShowWindow((HWND)hInstance, nShowCmd);
    Helpers::UpdateWindow((HWND)hInstance, 0, unused_ptr);

    // ==================== 消息循环 ====================
LABEL_MESSAGE_LOOP:
    while (!MsgWaitForMultipleObjects(1u, &timer_handle, 0, 0xFFFFFFFF, 0x4FFu))
    {
        SetWaitableTimer(timer_handle, &due_time, 0, 0, 0, 0);
        if (g_pCGameManager)
            CGameManager_PerformGameUpdate(g_pCGameManager);
    }

    while (1)
    {
        if (!PeekMessageW(&msg, 0, 0, 0, 1u))
            goto LABEL_MESSAGE_LOOP;
        if (msg.message == 18)  // WM_QUIT
            break;
        if (!TranslateAcceleratorW((HWND)hInstance, accel_table, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    wParam = msg.wParam;
    goto LABEL_CLEANUP;

    // ==================== 错误弹窗（仅 CGameManager_Init 失败时到达） ====================
LABEL_DISPERROR:
    DispError(0, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AAA);

    // ==================== 统一清理出口 ====================
LABEL_CLEANUP:
    if (timer_handle)
    {
        Helpers::CloseHandle(timer_handle, 0, unused_ptr);
        timer_handle = 0;
    }

    if (g_pCGameManager)
    {
        CGameManager_dtor(g_pCGameManager);
        g_pCGameManager = 0;
    }

    // 【安全保护】wisp_ptr 可能为 NULL（WISP 绕过时），已通过 if 保护
    if (wisp_ptr)
    {
        (*(void(__stdcall**)(LPVOID))(*reinterpret_cast<uint32_t*>(wisp_ptr) + 8))(wisp_ptr);
        wisp_ptr = 0;
    }

    if (com_initialized)
        CoUninitialize();

    WppCleanupUm();
    init_step = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();

    return wParam;
}
