#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CGameBoard::AddBallToUpdateList(CGameBoard* self, CBall* a2)
{
  int v3; // ecx
  uint8_t v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CGameBoard::AddBallToUpdateList", 0);
  v3 = *((uint32_t *)self + 301);
  if ( v3 < 64 )
  {
    *((uint32_t *)self + v3 + 302) = (uint32_t)a2;
    ++*((uint32_t *)self + 301);
  }
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
