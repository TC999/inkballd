#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CTileManager::SetTiles(void* self, uint32_t a2)
{
  uint32_t v3; // eax
  uint32_t v4; // ecx
  uint8_t v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "CTileManager::SetTiles", 0);
  v6 = 0;
  if ( a2 )
  {
    v3 = a2 - *((uint32_t *)self + 10);
    v4 = *((uint32_t *)self + 11);
    if ( v3 >= v4 )
    {
      *((uint32_t *)self + 9) += v3 / v4;
      *((uint32_t *)self + 10) = v4 * (a2 / v4);
      (*(void (__fastcall **)(void*, uint32_t))(*(uint32_t *)self + 4))(self, a2 % v4);
    }
  }
  else
  {
    *((uint32_t *)self + 10) = 0;
  }
  v6 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
}
