#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CBall*__thiscall CGameBoard::GetBall(CGameBoard *this, int a2)
{
  int v3; // esi
  uint8_t v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::GetBall", 0);
  v3 = *((uint32_t *)this + a2 + 657);
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return (CBall*)v3;
}

#endif
