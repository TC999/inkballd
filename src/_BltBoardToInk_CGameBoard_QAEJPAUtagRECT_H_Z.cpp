#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int __thiscall CGameBoard::BltBoardToInk(CGameBoard *this, struct tagRECT *a2, int a3)
{
  int v3; // esi
  uint8_t v5[8]; // [esp+10h] [ebp-18h] BYREF
  int v6[3]; // [esp+18h] [ebp-10h] BYREF
  int v7; // [esp+24h] [ebp-4h]

  v6[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::BltBoardToInk", v6);
  v7 = 0;
  CDisplay::ClearInk(g_pDisplay, a2, a3);
  v3 = v6[0];
  v7 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return v3;
}

#endif