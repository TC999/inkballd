#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void Restore_CTileManager(CTileManager *self)
{
    void* DDrawSurface; // auto-declared
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CTileManager::Restore", 0);
  v4 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pTileManagerSurface);
  DDrawSurface->Restore();
  (*(void (**)(CTileManager *))(*(uint32_t *)self + 4))(self);
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
