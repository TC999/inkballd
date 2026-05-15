#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CGameBoard::AddBall(CGameBoard *self, CBall* a2)
{
  uint32_t *v3; // eax
  int v4; // edx
  uint8_t v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "CGameBoard::AddBall", 0);
  v3 = (uint32_t *)(reinterpret_cast<char*>(self) + 2624);
  v4 = *((uint32_t *)self + 656);
  if ( v4 < 64 )
  {
    *((uint32_t *)a2 + 41) = v4;
    *((uint32_t *)self + (*v3)++ + 657) = (uint32_t)a2;
    ++*((uint32_t *)self + 2473);
  }
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
}
