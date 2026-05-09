#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
LRESULT __stdcall MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, uint32_t *lParam)
{
  LRESULT v4; // edi
  HMENU Menu; // eax
  LONG v7; // eax
  int v8; // eax
  int v9; // ecx
  LONG v10; // eax
  HICON IconW; // eax
  HRESULT Instance; // ebx
  OLECHAR *v13; // esi
  BOOL v14; // [esp-8h] [ebp-BA4h]
  BOOL v15; // [esp-8h] [ebp-BA4h]
  LONG WindowLongW; // [esp-4h] [ebp-BA0h]
  LONG v17; // [esp-4h] [ebp-BA0h]
  int*v18; // [esp+0h] [ebp-B9Ch]
  int*v19; // [esp+0h] [ebp-B9Ch]
  uint8_t v21[8]; // [esp+20h] [ebp-B7Ch] BYREF
  HMENU hMenu; // [esp+28h] [ebp-B74h] BYREF
  HWND v23; // [esp+2Ch] [ebp-B70h]
  _OSVERSIONINFOW VersionInformation; // [esp+30h] [ebp-B6Ch] BYREF
  tagPAINTSTRUCT Paint; // [esp+144h] [ebp-A58h] BYREF
  WCHAR szOtherStuff[1024]; // [esp+184h] [ebp-A18h] BYREF
  WCHAR szApp[266]; // [esp+984h] [ebp-218h] BYREF
  int v28; // [esp+B98h] [ebp-4h]

  v4 = 0;
  v23 = hWnd;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "MainWndProc", 0);
  v28 = 0;
  Menu = GetMenu(hWnd);
  hMenu = Menu;
  if ( Msg > 0x86 )
  {
    if ( Msg > 0x212 )
    {
      switch ( Msg )
      {
        case 0x232u:
          CGameManager::UpdateTime(g_pCGameManager);
          break;
        case 0x2A3u:
          g_fMouseInside = 0;
          break;
        case 0x30Fu:
          CGameBoard::QueryNewPallete(g_pCGameBoard);
          break;
      }
      goto LABEL_80;
    }
    if ( Msg == 530 )
    {
      CGameManager::UpdateTime(g_pCGameManager);
      if ( !*((uint32_t *)g_pCGameManager + 2) )
        *((uint32_t *)g_pCGameManager + 1) = 1;
      goto LABEL_80;
    }
    if ( Msg != 273 )
    {
      if ( Msg != 512 )
      {
        if ( Msg == 516 )
        {
          CGameManager::DropWallTile(g_pCGameManager, (void*)(__int16)lParam, SHIWORD(lParam));
        }
        else if ( Msg == 529 )
        {
          *((uint32_t *)g_pCGameManager + 1) = 0;
        }
        goto LABEL_80;
      }
      goto LABEL_30;
    }
    if ( (uint16_t)wParam > 0x9C45u )
    {
      switch ( (uint16_t)wParam )
      {
        case 0x9C46u:
          CheckMenuItem(Menu, iLastChecked, 0);
          iLastChecked = 40006;
          CheckMenuItem(hMenu, 0x9C46u, 8u);
          CBoardManager::SetDifficulty(g_CBoardManager, 4);
          goto LABEL_50;
        case 0x9C4Au:
          if ( *((uint32_t *)g_pCGameManager + 2) )
          {
            *((uint32_t *)g_pCGameManager + 1) = 1;
            *((uint32_t *)g_pCGameManager + 2) = 0;
            *(uint32_t *)(*((uint32_t *)g_pCGameBoard + 2481) + 16) = 1;
            CheckMenuItem(Menu, 0x9C4Au, 0);
            g_fLastPauseFromMenu = 0;
          }
          else
          {
            *((uint32_t *)g_pCGameManager + 1) = 0;
            *((uint32_t *)g_pCGameManager + 2) = 1;
            *(uint32_t *)(*((uint32_t *)g_pCGameBoard + 2481) + 16) = 0;
            CheckMenuItem(Menu, 0x9C4Au, 8u);
            g_fLastPauseFromMenu = 1;
          }
          goto LABEL_53;
        case 0x9C68u:
          hMenu = 0;
          Instance = CoCreateInstance(
                       &_GUID_8cec58e7_07a1_11d9_b15e_000d56bfe6ee,
                       0,
                       0x17u,
                       &_GUID_8cec5884_07a1_11d9_b15e_000d56bfe6ee,
                       (LPVOID *)&hMenu);
          if ( Instance < 0 )
            goto LABEL_67;
          v13 = SysAllocString(L"mshelp://Windows/?id=c209fb0d-530b-43ce-954b-7c91aeca0013");
          if ( v13 )
          {
            Instance = (*(int (__stdcall **)(HMENU, OLECHAR *))(*(uint32_t *)hMenu + 12))(hMenu, v13);
            SysFreeString(v13);
          }
          (*(void (__stdcall **)(HMENU))(*(uint32_t *)hMenu + 8))(hMenu);
          if ( Instance < 0 )
LABEL_67:
            DispError(v23, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AA9);
          goto LABEL_53;
        case 0x9C69u:
          szOtherStuff[0] = 0;
          Helpers::LoadStringW(g_hInst, (HINSTANCE)0x3A98, szApp, (uint16_t *)0x104, 0, v18);
          memset(&VersionInformation, 0, sizeof(VersionInformation));
          VersionInformation.dwOSVersionInfoSize = 276;
          GetVersionExW(&VersionInformation);
          StringCchPrintfExW(
            (STRSAFE_LPWSTR *)0x9C46,
            szOtherStuff,
            0x400u,
            0,
            0,
            0x100u,
            (wchar_t *)L"%s %lu.%lu.%lu",
            szApp,
            VersionInformation.dwMajorVersion,
            VersionInformation.dwMinorVersion,
            VersionInformation.dwBuildNumber);
          IconW = Helpers::LoadIconW(g_hInst, (HINSTANCE)0x65, 0, v19);
          ShellAboutW(v23, szApp, szOtherStuff, IconW);
          goto LABEL_53;
      }
      if ( (uint16_t)wParam != 40042 )
        goto LABEL_80;
      CInk::ClearInk(*((CInk **)g_pCGameBoard + 2481));
      BltBoardToInk(0);
    }
    else
    {
      if ( (uint16_t)wParam == 40005 )
      {
        CheckMenuItem(Menu, iLastChecked, 0);
        iLastChecked = 40005;
        CheckMenuItem(hMenu, 0x9C45u, 8u);
        CBoardManager::SetDifficulty(g_CBoardManager, 3);
        goto LABEL_50;
      }
      if ( (uint16_t)wParam == 40000 )
      {
        Helpers::PostMessageW(v23, (HWND)0x10, 0, 0, 0, v18);
        goto LABEL_53;
      }
      if ( (uint16_t)wParam != 40001 )
      {
        switch ( (uint16_t)wParam )
        {
          case 0x9C42u:
            CheckMenuItem(Menu, iLastChecked, 0);
            iLastChecked = 40002;
            CheckMenuItem(hMenu, 0x9C42u, 8u);
            CBoardManager::SetDifficulty(g_CBoardManager, 0);
            break;
          case 0x9C43u:
            CheckMenuItem(Menu, iLastChecked, 0);
            iLastChecked = 40003;
            CheckMenuItem(hMenu, 0x9C43u, 8u);
            CBoardManager::SetDifficulty(g_CBoardManager, 1);
            break;
          case 0x9C44u:
            CheckMenuItem(Menu, iLastChecked, 0);
            iLastChecked = 40004;
            CheckMenuItem(hMenu, 0x9C44u, 8u);
            CBoardManager::SetDifficulty(g_CBoardManager, 2);
            break;
          default:
            goto LABEL_80;
        }
LABEL_50:
        CBoardManager::LoadRandomBoardFromResources((CBoardManager *)g_CBoardManager, &BoardData, &iBoardSizeBytes);
        CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
        goto LABEL_53;
      }
      KillPlayer(2);
      CBoardManager::LoadRandomBoardFromResources((CBoardManager *)g_CBoardManager, &BoardData, &iBoardSizeBytes);
      CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
    }
    InvalidateRect(v23, 0, 0);
    goto LABEL_53;
  }
  if ( Msg == 134 )
  {
    if ( g_pCGameManager && !g_fLastPauseFromMenu )
      *((uint32_t *)g_pCGameManager + 1) = wParam != 0;
LABEL_30:
    if ( !g_fMouseInside )
    {
      Rect.left = 16;
      Rect.bottom = 0;
      Rect.right = (LONG)v23;
      g_fMouseInside = 1;
      Rect.top = 2;
      TrackMouseEvent((LPTRACKMOUSEEVENT)&Rect);
    }
    goto LABEL_80;
  }
  if ( Msg > 0x12 )
  {
    switch ( Msg )
    {
      case 0x14u:
        goto LABEL_53;
      case 0x24u:
        Rect.left = 0;
        Rect.top = 0;
        if ( g_pCGameBoard )
        {
          Rect.right = *((uint32_t *)g_pCGameBoard + 2465);
          Rect.bottom = *((uint32_t *)g_pCGameBoard + 2466);
          WindowLongW = GetWindowLongW(v23, -20);
          v14 = GetMenu(v23) != 0;
          v7 = GetWindowLongW(v23, -16);
          AdjustWindowRectEx(&Rect, v7, v14, WindowLongW);
          v8 = Rect.right - Rect.left;
          v9 = Rect.bottom - Rect.top;
          lParam[6] = Rect.right - Rect.left;
          lParam[7] = v9;
          lParam[8] = v8;
          lParam[9] = v9;
        }
        else
        {
          Rect.right = 544;
          Rect.bottom = 586;
          v17 = GetWindowLongW(v23, -20);
          v15 = GetMenu(v23) != 0;
          v10 = GetWindowLongW(v23, -16);
          AdjustWindowRectEx(&Rect, v10, v15, v17);
          lParam[8] = Rect.right - Rect.left;
          lParam[9] = Rect.bottom - Rect.top;
        }
        goto LABEL_53;
      case 0x7Eu:
        CInk::OnDisplayChange(*((CInk **)g_pCGameBoard + 2481));
        break;
    }
    goto LABEL_80;
  }
  switch ( Msg )
  {
    case 0x12u:
    case 2u:
      PostQuitMessage(0);
LABEL_19:
      v28 = -1;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
      return v4;
    case 3u:
      CGameBoard::UpdateBounds(g_pCGameBoard);
      goto LABEL_53;
    case 5u:
      if ( g_pCGameManager )
      {
        if ( wParam == 4 || wParam == 1 )
        {
          *((uint32_t *)g_pCGameManager + 1) = 0;
        }
        else if ( !*((uint32_t *)g_pCGameManager + 2) )
        {
          *((uint32_t *)g_pCGameManager + 1) = 1;
        }
        CGameBoard::UpdateBounds(g_pCGameBoard);
      }
      goto LABEL_80;
  }
  if ( Msg != 15 )
  {
LABEL_80:
    v4 = DefWindowProcW(v23, Msg, wParam, (LPARAM)lParam);
    goto LABEL_19;
  }
  BeginPaint(v23, &Paint);
  CGameBoard::Paint(g_pCGameBoard);
  EndPaint(v23, &Paint);
LABEL_53:
  v28 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
  return 0;
}
