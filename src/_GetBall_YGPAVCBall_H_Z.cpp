#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CBall*__stdcall GetBall(int a1)
{
  CBall*Ball; // eax
  CBall*v2; // esi
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "GetBall", 0);
  v5 = 0;
  Ball = CGameBoard::GetBall(g_pCGameBoard, a1);
  v5 = -1;
  v2 = Ball;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}

#endif
