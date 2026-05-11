#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CTileManager::ResetTileCount(CTileManager *this)
{
  int v2; // eax
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTileManager::ResetTileCount", 0);
  v2 = *(uint32_t *)this;
  v4 = 0;
  *((uint32_t *)this + 9) = 0;
  *((uint32_t *)this + 10) = 0;
  (*(void (__thiscall **)(CTileManager *))(v2 + 4))(this);
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}

#endif
