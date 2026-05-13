#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

int CTileManager::InitSurface()
{
  int Surface; // eax
  int v3; // esi
  void*v5; // [esp-8h] [ebp-30h]
  uint32_t v6; // [esp-4h] [ebp-2Ch]
  uint8_t v7[8]; // [esp+10h] [ebp-18h] BYREF
  int v8[3]; // [esp+18h] [ebp-10h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  v8[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock *>(v7), "CTileManager::InitSurface", v8);
  v6 = *((uint32_t *)this + 4);
  v5 = (void*)*((uint32_t *)this + 3);
  v9 = 0;
  Surface = CDisplay::CreateSurface(g_pDisplay, &g_pTileManagerSurface, v5, v6);
  v9 = -1;
  v8[0] = Surface;
  v3 = Surface;
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
  return v3;
}
