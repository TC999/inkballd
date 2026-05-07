#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include "defs.h"
#include <stdio.h>
#include <wchar.h>
#include <time.h>
#include <CommCtrl.h>
#include <float.h>
#pragma comment(lib, "Comctl32.lib")
#define snwprintf _snwprintf
#define wtol _wtol
#define __usercall

int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
  HRESULT v5; // eax
  HRESULT v6; // eax
  WPARAM wParam; // ebx
  HRESULT v8; // eax
  void *v9; // ecx
  CGameManager *v10; // ecx
  unsigned int Difficulty; // eax
  WCHAR v12; // ax
  unsigned __int16 *v13; // ecx
  unsigned __int16 *v14; // eax
  char LastError; // al
  int *v16; // [esp+0h] [ebp-6Ch]
  tagMSG Msg; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v18[8]; // [esp+38h] [ebp-34h] BYREF
  LARGE_INTEGER DueTime; // [esp+40h] [ebp-2Ch] BYREF
  void *v20; // [esp+48h] [ebp-24h]
  HACCEL hAccTable; // [esp+4Ch] [ebp-20h] BYREF
  int v22; // [esp+50h] [ebp-1Ch] BYREF
  LPVOID ppv; // [esp+54h] [ebp-18h] BYREF
  HANDLE hTimer; // [esp+58h] [ebp-14h] BYREF
  int v25; // [esp+68h] [ebp-4h]

  WPP_INIT_CONTROL_ARRAY(&WPP_MAIN_CB);
  WPP_REGISTRATION_GUIDS = (int)WPP_ThisDir_CTLGUID_ControlGuid;
  dword_10B2704 = (int)WPP_ThisDir_CTLGUID_MobTabPerfTraceProvider;
  WPP_GLOBAL_Control = &WPP_MAIN_CB;
  WppInitUm(L"TabletPC\\InkBall");
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "wWinMain", 0);
  v25 = 0;
  HeapSetInformation(0, HeapEnableTerminationOnCorruption, 0, 0);
  v22 = 0;
  if ( !CanRunInkball(&v22) )
  {
    if ( !v22 )
      DispError(0, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AA8);
    WppCleanupUm();
    v25 = -1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
    return -1;
  }
  if ( WinSqmIsOptedIn() )
    _WinSqmDWORDEvent(&SQM_INCREMENT_DWORD, 0, 157, 1);
  SetProcessDPIAware();
  v5 = RegisterApplicationRestart(L" ", 0);
  if ( v5 < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xCu, &stru_1003520, v5);
  v6 = RegisterApplicationRecoveryCallback(InkBallRecovery, 0, 0, 0);
  if ( v6 < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xDu, &stru_1003520, v6);
  wParam = -1;
  ppv = 0;
  hTimer = 0;
  v8 = CoInitialize(0);
  v22 = v8 >= 0;
  if ( v8 < 0 )
  {
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xEu, &stru_1003520, v8);
    goto LABEL_61;
  }
  if ( EnableClassicWispWithPtr(&ppv) )
  {
    g_hInst = hInstance;
    if ( WinInit(hInstance, nShowCmd, (HWND *)&hInstance, &hAccTable) < 0 )
      goto LABEL_61;
    _set_new_handler((int (__cdecl *)(unsigned int))new_oom_handler);
    LOBYTE(v25) = 1;
    v9 = operator new(0x14u);
    v20 = v9;
    LOBYTE(v25) = 2;
    if ( v9 )
      v10 = CGameManager::CGameManager((CGameManager *)v9, (HWND)hInstance);
    else
      v10 = 0;
    g_pCGameManager = v10;
    v25 = 0;
    if ( CGameManager::Init(v10) >= 0 )
    {
      Difficulty = CRegistryManager::ReadDifficulty((CRegistryManager *)&g_CRegistryManager);
      CBoardManager::SetDifficulty(&g_CBoardManager, Difficulty);
      if ( !*lpCmdLine )
        goto LABEL_43;
      if ( *lpCmdLine == 47 )
      {
        v12 = lpCmdLine[1];
        if ( v12 == 114 || v12 == 82 )
        {
          if ( lpCmdLine[2] != 58 )
            ExitBadCommandLine((HWND)hInstance);
          v13 = lpCmdLine + 3;
          if ( lpCmdLine[3] == 34 )
            v13 = lpCmdLine + 4;
          v14 = &v13[wcslen(v13) - 1];
          if ( *v14 == 34 )
            *v14 = 0;
          if ( !CBoardManager::LoadBoardFromResources(
                  (CBoardManager *)&g_CBoardManager,
                  v13,
                  &BoardData,
                  &iBoardSizeBytes) )
LABEL_43:
            CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
        }
      }
      if ( g_pCGameManager )
      {
        CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
        *((_DWORD *)g_pCGameManager + 1) = 1;
      }
      SetMenuChecks((HWND)hInstance);
      hTimer = CreateWaitableTimerW(0, 0, 0);
      if ( !hTimer && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LastError = GetLastError();
        WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x12u, &stru_1003520, LastError);
      }
      DueTime.QuadPart = -150000;
      SetWaitableTimer(hTimer, &DueTime, 0, 0, 0, 0);
      ShowWindow((HWND)hInstance, nShowCmd);
      Helpers::UpdateWindow((HWND)hInstance, 0, v16);
LABEL_52:
      while ( !MsgWaitForMultipleObjects(1u, &hTimer, 0, 0xFFFFFFFF, 0x4FFu) )
      {
        SetWaitableTimer(hTimer, &DueTime, 0, 0, 0, 0);
        if ( g_pCGameManager )
          CGameManager::PerformGameUpdate(g_pCGameManager);
      }
      while ( 1 )
      {
        if ( !PeekMessageW(&Msg, 0, 0, 0, 1u) )
          goto LABEL_52;
        if ( Msg.message == 18 )
          break;
        if ( !TranslateAcceleratorW((HWND)hInstance, hAccTable, &Msg) )
        {
          TranslateMessage(&Msg);
          DispatchMessageW(&Msg);
        }
      }
      wParam = Msg.wParam;
      goto LABEL_61;
    }
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x11u, &stru_1003520);
  }
  else if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
  {
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xFu, &stru_1003520);
  }
  DispError(0, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AAA);
LABEL_61:
  if ( hTimer )
  {
    Helpers::CloseHandle(hTimer, 0, v16);
    hTimer = 0;
  }
  if ( g_pCGameManager )
  {
    CGameManager::`scalar deleting destructor'(g_pCGameManager, 1);
    g_pCGameManager = 0;
  }
  if ( ppv )
  {
    (*(void (__stdcall **)(LPVOID))(*(_DWORD *)ppv + 8))(ppv);
    ppv = 0;
  }
  if ( v22 )
    CoUninitialize();
  WppCleanupUm();
  v25 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
  return wParam;
}
