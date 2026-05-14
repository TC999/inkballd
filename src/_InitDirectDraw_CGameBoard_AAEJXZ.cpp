#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int InitDirectDraw_CGameBoard(CGameBoard *self)
{
    void* LPDDCOLORKEY;
    void* InkBuffer;
  int v2; // esi
  void*v3; // ecx
  CDisplay *v4; // eax
  int*v7; // [esp+0h] [ebp-2C0h]
  int*v8; // [esp+0h] [ebp-2C0h]
  uint8_t v9[8]; // [esp+10h] [ebp-2B0h] BYREF
  void*v10; // [esp+18h] [ebp-2A8h]
  uint32_t v11[3]; // [esp+1Ch] [ebp-2A4h] BYREF
  int WindowedDisplay; // [esp+28h] [ebp-298h] BYREF
  WCHAR Text[256]; // [esp+2Ch] [ebp-294h] BYREF
  WCHAR Caption[72]; // [esp+22Ch] [ebp-94h] BYREF
  int v15; // [esp+2BCh] [ebp-4h]

  v2 = 0;
  v11[2] = self;
  WindowedDisplay = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameBoard::InitDirectDraw", &WindowedDisplay);
  v15 = 1;
  v3 = operator new(0x38u);
  v10 = v3;
  LOBYTE(v15) = 2;
  if ( v3 )
    v4 = CDisplay::CDisplay((CDisplay *)v3);
  else
    v4 = 0;
  g_pDisplay = v4;
  v15 = 0;
  if ( !v4 )
    WindowedDisplay = -2147024882;
  if ( WindowedDisplay < 0 )
    goto LABEL_11;
  WindowedDisplay = CDisplay::CreateWindowedDisplay(
                      v4,
                      *((HWND *)self + 2480),
                      *((uint32_t *)self + 2465),
                      *((uint32_t *)self + 2466));
  if ( WindowedDisplay >= 0 )
    goto LABEL_16;
  if ( g_pDisplay )
  {
    void* InkBuffer; // auto-declared
    CDisplay::scalar_deleting_destructor(g_pDisplay, 1);
    g_pDisplay = 0;
  }
  if ( WindowedDisplay >= 0 )
  {
LABEL_16:
    v11[0] = CDisplay::ConvertGDIColor(g_pDisplay, 0x10101u);
    v11[1] = CDisplay::ConvertGDIColor(g_pDisplay, 0xFFFFFFu);
    InkBuffer = CDisplay::GetInkBuffer(g_pDisplay);
    InkBuffer->lpVtbl->SetColorKey(InkBuffer, 2, (LPDDCOLORKEY)v11);
    WindowedDisplay = 0;
  }
  else
  {
LABEL_11:
    memset(Caption, 0, 128);
    memset(Text, 0, sizeof(Text));
    Helpers::LoadStringW(0, (HINSTANCE)0x3AA3, Caption, (uint16_t *)0x40, 0, v7);
    if ( CGameBoard::IsRemoteSession(self) == 1 )
      Helpers::LoadStringW(0, (HINSTANCE)0x3AAB, Text, (uint16_t *)0x100, 0, v8);
    else
      Helpers::LoadStringW(0, (HINSTANCE)0x3AA5, Text, (uint16_t *)0x100, 0, v8);
    MessageBoxW(*((HWND *)self + 2480), Text, Caption, 0x10u);
    v2 = WindowedDisplay;
  }
  v15 = -1;
  ((Helpers::CLogBlock*)v9)->~CLogBlock();
  return v2;
}

