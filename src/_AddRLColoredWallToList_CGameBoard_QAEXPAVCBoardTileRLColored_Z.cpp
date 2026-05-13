#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void __thiscall CGameBoard::AddRLColoredWallToList(CGameBoard *this, CBoardTileRLColored*a2)
{
  int v3; // ecx
  uint8_t v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddRLColoredWallToList", 0);
  v3 = *((uint32_t *)this + 366);
  if ( v3 < 289 )
  {
    *((uint32_t *)this + v3 + 367) = a2;
    ++*((uint32_t *)this + 366);
  }
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}

#endif