#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall BallOnTile(CBoardTile*a1)
{
  int v1; // eax
  int v2; // esi
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "BallOnTile", 0);
  v5 = 0;
  v1 = CGameBoard::BallOnTile(g_pCGameBoard, a1);
  v5 = -1;
  v2 = v1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}

#endif
