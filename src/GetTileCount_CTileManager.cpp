#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
extern void DrawToSurface_CTileManager(CTileManager* self);
int GetTileCount_CTileManager(CTileManager* self)
{
  int v2; // eax
  int v3; // esi
  uint8_t v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "CTileManager::GetTileCount", 0);
  v2 = *((uint32_t *)self + 9);
  v6 = 0;
  if ( v2 )
  {
    *((uint32_t *)self + 9) = v2 - 1;
    DrawToSurface_CTileManager(self);
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  v6 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return v3;
}
