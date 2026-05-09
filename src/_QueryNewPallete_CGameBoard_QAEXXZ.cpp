#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CGameBoard::QueryNewPallete(CGameBoard *this)
{
  struct IDirectDrawSurface7 *FrontBuffer; // eax
  struct IDirectDrawSurface7 *v2; // eax
  uint8_t v3[8]; // [esp+10h] [ebp-18h] BYREF
  LPDIRECTDRAWPALETTE v4[3]; // [esp+18h] [ebp-10h] BYREF
  int v5; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::QueryNewPallete", 0);
  v5 = 0;
  v4[0] = 0;
  FrontBuffer = CDisplay::GetFrontBuffer(g_pDisplay);
  FrontBuffer->lpVtbl->GetPalette(FrontBuffer, v4);
  v2 = CDisplay::GetFrontBuffer(g_pDisplay);
  v2->lpVtbl->SetPalette(v2, v4[0]);
  if ( v4[0] )
  {
    (*(void (__stdcall **)(LPDIRECTDRAWPALETTE))(*(uint32_t *)v4[0] + 8))(v4[0]);
    v4[0] = 0;
  }
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
