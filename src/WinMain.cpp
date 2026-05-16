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
    int* unused_ptr = nullptr;
    tagMSG msg;
    uint8_t log_buffer[8];
    LARGE_INTEGER due_time;
    void* com_ptr;
    HACCEL accel_table;
    int com_initialized;
    LPVOID wisp_ptr;
    HANDLE timer_handle;
    int init_step;

    // ==================== WPP Tracing ��ʼ�� ====================
    WPP_INIT_CONTROL_ARRAY(&WPP_MAIN_CB);
    WPP_REGISTRATION_GUIDS = WPP_ThisDir_CTLGUID_ControlGuid;
    dword_10B2704 = (int)WPP_ThisDir_CTLGUID_MobTabPerfTraceProvider;
    WPP_GLOBAL_Control = reinterpret_cast<uint64_t>(&WPP_MAIN_CB);
    WppInitUm((int)L"TabletPC\\InkBall");

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "wWinMain", 0);
    init_step = 0;

    HeapSetInformation(0, HeapEnableTerminationOnCorruption, 0, 0);
    com_initialized = 0;

    // [����] CanRunInkball ����֮ǰ��ע�͵�

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
    // ���޸ĵ�1���ƹ� EnableClassicWispWithPtr
    //
    // ԭ�߼������� EnableClassicWispWithPtr ��ʼ�� WISP ��д����ϵͳ��
    //         ʧ����ֱ���䵽 DispError ������
    //
    // ���⣺�ִ�ϵͳ��Win10/11���Ǵ��������������ȱ�� Tablet PC ��
    //       COM ���ע�ᣬ���¸ú���ʧ�ܡ�
    //
    // �޸������Ե��ã�ʧ��ʱ����ϣ�����¼��־�������
    //       wisp_ptr Ϊ NULL ʱ������������ͨ�� if(wisp_ptr) ������
    //       ���������
    // =====================================================================
    {
        int wisp_result = EnableClassicWispWithPtr(&wisp_ptr);
        if (!wisp_result)
        {
            // WISP ��ʼ��ʧ�� ���� ��¼��־�������
            if (WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
                ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
            {
                WPP_SF_(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0xFu, &stru_1003520);
            }
            wisp_ptr = NULL;  // ȷ��Ϊ NULL������ʱ��ȫ����
        }
    }

    // =====================================================================
    // ����Ϊ������ʼ�����̣�ԭ EnableClassicWispWithPtr �ɹ���֧�ڵ�ȫ�����ݣ�
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
    // ���޸ĵ�2��CGameManager_Init ʧ��ʱ��¼����ֵ�������Ų�
    // =====================================================================
    if (CGameManager_Init(game_manager) < 0)
    {
        // Init ʧ�ܣ���¼ trace �󵯴���������·���Ĵ�����ʾ��
        if (WPP_GLOBAL_Control != (uint64_t)&WPP_GLOBAL_Control &&
            ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
        {
            WPP_SF_(*(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2), 0x11u, &stru_1003520);
        }
        // ��� CGameManager_Init ��Ȼʧ�ܣ������ڴ˴��� OutputDebugString �Ų�
        // OutputDebugStringA("[wWinMain] CGameManager_Init FAILED\n");
        goto LABEL_DISPERROR;  // ��·��������������Ϊ��Ϸ���ĳ�ʼ��ʧ��ȷʵ��Ҫ��ʾ
    }

    difficulty = CRegistryManager::ReadDifficulty((CRegistryManager*)&g_CRegistryManager);
    ((CBoardManager*)g_CBoardManager)->SetDifficulty(difficulty);

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

            if (!((CBoardManager*)g_CBoardManager)->LoadBoardFromResources(
                reinterpret_cast<unsigned __int16*>(file_path),
                reinterpret_cast<unsigned __int8*>(&BoardData),
                &iBoardSizeBytes))
            {
            LABEL_LOAD_RANDOM:
                ((CBoardManager*)g_CBoardManager)->LoadRandomBoardFromResources(
                    (unsigned char*)&BoardData, &iBoardSizeBytes);
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

    // ==================== ��Ϣѭ�� ====================
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

    // ==================== ���󵯴����� CGameManager_Init ʧ��ʱ��� ====================
LABEL_DISPERROR:
    DispError(0, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AAA);

    // ==================== ͳһ�������� ====================
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

    // ����ȫ������wisp_ptr ����Ϊ NULL��WISP �ƹ�ʱ������ͨ�� if ����
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
