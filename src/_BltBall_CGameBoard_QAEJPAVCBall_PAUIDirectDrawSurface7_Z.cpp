#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CGameBoard::BltBall(CGameBoard *this, struct tagRECT **a2, struct IDirectDrawSurface7 *a3)
{
  int v5; // eax
  int v6; // esi
  uint8_t v10[8]; // [esp+20h] [ebp-18h] BYREF
  int v11[3]; // [esp+28h] [ebp-10h] BYREF
  int v12; // [esp+34h] [ebp-4h]

  v11[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::BltBall", v11);
  v12 = 0;
  CBoardObject::GetBoundingRect((CBoardObject *)a2, &v9);
  lpVtbl = a3->lpVtbl;
  v8 = a2[8];
  DDrawSurface = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v5 = lpVtbl->Blt(a3, &v9, DDrawSurface, v8, 0x8000, 0);
  v12 = -1;
  v11[0] = v5;
  v6 = v5;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return v6;
}
