#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CGameBoard::AddBallToUpdateList(CGameBoard *this, CBall*a2)
{
  int v3; // ecx
  uint8_t v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddBallToUpdateList", 0);
  v3 = *((uint32_t *)this + 301);
  if ( v3 < 64 )
  {
    *((uint32_t *)this + v3 + 302) = a2;
    ++*((uint32_t *)this + 301);
  }
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}

#endif
