#include "global_types.h"
#include <windows.h>
#include <cstdint>
#include <cstdio>
#include <cwchar>
#include <ctime>
#include <CommCtrl.h>
#include <float.h>
#pragma comment(lib, "Comctl32.lib")

extern "C" {
    int snwprintf(wchar_t* buffer, size_t count, const wchar_t* format, ...);
    long wtol(const wchar_t* str);
    
    // External function declarations
    extern int CanRunInkball(int* result);
    extern void DispError(HWND hWnd, HINSTANCE hInstance, HINSTANCE hPrevInstance);
    extern int WinSqmIsOptedIn();
    extern void _WinSqmDWORDEvent(void* param1, int param2, int param3, int param4);
    extern int InkBallRecovery(void* param1, int param2);
    extern int EnableClassicWispWithPtr(LPVOID* ptr);
    extern int WinInit(HINSTANCE hInstance, int nCmdShow, HWND* hWnd, HACCEL* hAccel);
    extern void* new_oom_handler(unsigned int size);
    extern void ExitBadCommandLine(HWND hWnd);
    extern int CBoardManager::LoadBoardFromResources(CBoardManager* manager, const wchar_t* name, void* boardData, int* boardSize);
    extern int CBoardManager::LoadRandomBoardFromResources(CBoardManager* manager, void* boardData, int* boardSize);
    extern void SetMenuChecks(HWND hWnd);
    extern void Helpers::UpdateWindow(HWND hWnd, int unused, int* param);
}

int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
  HRESULT result; // eax
  HRESULT coinit_result; // eax
  WPARAM wParam; // ebx
  HRESULT create_result; // eax
  void* game_manager_ptr; // ecx
  CGameManager* game_manager; // ecx
  uint32_t difficulty; // eax
  WCHAR first_char; // ax
  uint16_t* file_path; // ecx
  uint16_t* file_path_end; // eax
  char last_error; // al
  int* unused_ptr; // [esp+0h] [ebp-6Ch]
  tagMSG msg; // [esp+10h] [ebp-5Ch] BYREF
  uint8_t log_buffer[8]; // [esp+38h] [ebp-34h] BYREF
  LARGE_INTEGER due_time; // [esp+40h] [ebp-2Ch] BYREF
  void* com_ptr; // [esp+48h] [ebp-24h]
  HACCEL accel_table; // [esp+4Ch] [ebp-20h] BYREF
  int com_initialized; // [esp+50h] [ebp-1Ch] BYREF
  LPVOID wisp_ptr; // [esp+54h] [ebp-18h] BYREF
  HANDLE timer_handle; // [esp+58h] [ebp-14h] BYREF
  int init_step; // [esp+68h] [ebp-4h]

  WPP_INIT_CONTROL_ARRAY(&WPP_MAIN_CB);
  WPP_REGISTRATION_GUIDS = (int)WPP_ThisDir_CTLGUID_ControlGuid;
  dword_10B2704 = (int)WPP_ThisDir_CTLGUID_MobTabPerfTraceProvider;
  WPP_GLOBAL_Control = &WPP_MAIN_CB;
  WppInitUm(L"TabletPC\\InkBall");
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "wWinMain", 0);
  init_step = 0;
  HeapSetInformation(0, HeapEnableTerminationOnCorruption, 0, 0);
  com_initialized = 0;
  if (!CanRunInkball(&com_initialized))
  {
    if (!com_initialized)
      DispError(0, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AA8);
    WppCleanupUm();
    init_step = -1;
    Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
    return -1;
  }
  if (WinSqmIsOptedIn())
    _WinSqmDWORDEvent(&SQM_INCREMENT_DWORD, 0, 157, 1);
  SetProcessDPIAware();
  result = RegisterApplicationRestart(L" ", 0);
  if (result < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
    WPP_SF_d(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0xCu, &stru_1003520, result);
  coinit_result = RegisterApplicationRecoveryCallback(InkBallRecovery, 0, 0, 0);
  if (coinit_result < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
    WPP_SF_d(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0xDu, &stru_1003520, coinit_result);
  wParam = -1;
  wisp_ptr = 0;
  timer_handle = 0;
  create_result = CoInitialize(0);
  com_initialized = create_result >= 0;
  if (create_result < 0)
  {
    if (WPP_GLOBAL_Control != &WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
      WPP_SF_d(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0xEu, &stru_1003520, create_result);
    goto LABEL_61;
  }
  if (EnableClassicWispWithPtr(&wisp_ptr))
  {
    g_hInst = hInstance;
    if (WinInit(hInstance, nShowCmd, reinterpret_cast<HWND*>(&hInstance), &accel_table) < 0)
      goto LABEL_61;
    _set_new_handler(reinterpret_cast<int(__cdecl*)(unsigned int)>(new_oom_handler));
    init_step = 1;
    game_manager_ptr = operator new(0x14u);
    com_ptr = game_manager_ptr;
    init_step = 2;
    if (game_manager_ptr)
      game_manager = CGameManager::CGameManager(reinterpret_cast<CGameManager*>(game_manager_ptr), (HWND)hInstance);
    else
      game_manager = 0;
    g_pCGameManager = game_manager;
    init_step = 0;
    if (CGameManager::Init(game_manager) >= 0)
    {
      difficulty = CRegistryManager::ReadDifficulty(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager));
      CBoardManager::SetDifficulty(&g_CBoardManager, difficulty);
      if (!*lpCmdLine)
        goto LABEL_43;
      if (*lpCmdLine == 47)
      {
        first_char = lpCmdLine[1];
        if (first_char == 114 || first_char == 82)
        {
          if (lpCmdLine[2] != 58)
            ExitBadCommandLine((HWND)hInstance);
          file_path = lpCmdLine + 3;
          if (lpCmdLine[3] == 34)
            file_path = lpCmdLine + 4;
          file_path_end = &file_path[wcslen(file_path) - 1];
          if (*file_path_end == 34)
            *file_path_end = 0;
          if (!CBoardManager::LoadBoardFromResources(
                  reinterpret_cast<CBoardManager*>(&g_CBoardManager),
                  file_path,
                  &BoardData,
                  &iBoardSizeBytes))
LABEL_43:
            CBoardManager::LoadRandomBoardFromResources(reinterpret_cast<CBoardManager*>(&g_CBoardManager), &BoardData, &iBoardSizeBytes);
        }
      }
      if (g_pCGameManager)
      {
        CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
        *reinterpret_cast<uint32_t*>(g_pCGameManager) = 1;
      }
      SetMenuChecks((HWND)hInstance);
      timer_handle = CreateWaitableTimerW(0, 0, 0);
      if (!timer_handle && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0)
      {
        last_error = GetLastError();
        WPP_SF_d(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0x12u, &stru_1003520, last_error);
      }
      due_time.QuadPart = -150000;
      SetWaitableTimer(timer_handle, &due_time, 0, 0, 0, 0);
      ShowWindow((HWND)hInstance, nShowCmd);
      Helpers::UpdateWindow((HWND)hInstance, 0, unused_ptr);
LABEL_52:
      while (!MsgWaitForMultipleObjects(1u, &timer_handle, 0, 0xFFFFFFFF, 0x4FFu))
      {
        SetWaitableTimer(timer_handle, &due_time, 0, 0, 0, 0);
        if (g_pCGameManager)
          CGameManager::PerformGameUpdate(g_pCGameManager);
      }
      while (1)
      {
        if (!PeekMessageW(&msg, 0, 0, 0, 1u))
          goto LABEL_52;
        if (msg.message == 18)
          break;
        if (!TranslateAcceleratorW((HWND)hInstance, accel_table, &msg))
        {
          TranslateMessage(&msg);
          DispatchMessageW(&msg);
        }
      }
      wParam = msg.wParam;
      goto LABEL_61;
    }
    if (WPP_GLOBAL_Control != &WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
      WPP_SF_(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0x11u, &stru_1003520);
  }
  else if (WPP_GLOBAL_Control != &WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 8) != 0)
  {
    WPP_SF_(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0xFu, &stru_1003520);
  }
  DispError(0, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AAA);
LABEL_61:
  if (timer_handle)
  {
    Helpers::CloseHandle(timer_handle, 0, unused_ptr);
    timer_handle = 0;
  }
  if (g_pCGameManager)
  {
    CGameManager::~CGameManager(g_pCGameManager);
    g_pCGameManager = 0;
  }
  if (wisp_ptr)
  {
    (*(void(__stdcall **)(LPVOID))(*reinterpret_cast<uint32_t*>(wisp_ptr) + 8))(wisp_ptr);
    wisp_ptr = 0;
  }
  if (com_initialized)
    CoUninitialize();
  WppCleanupUm();
  init_step = -1;
  Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
  return wParam;
}
