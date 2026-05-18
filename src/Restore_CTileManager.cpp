#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
extern void DrawToSurface_CTileManager(CTileManager* self);
void Restore_CTileManager(CTileManager *self)
{
    IDirectDrawSurface7* DDrawSurface;
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CTileManager::Restore", 0);
  v4 = 0;
  DDrawSurface = static_cast<IDirectDrawSurface7*>(CSurface::GetDDrawSurface(g_pTileManagerSurface));
  DDrawSurface->lpVtbl->Restore(DDrawSurface);
  DrawToSurface_CTileManager(self);
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
