#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void Restore_CScoreManager(CScoreManager *self)
{
    IDirectDrawSurface7* DDrawSurface;
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CScoreManager::Restore", 0);
  v4 = 0;
  DDrawSurface = static_cast<IDirectDrawSurface7*>(CSurface::GetDDrawSurface(g_pScoreManagerSurface));
  DDrawSurface->lpVtbl->Restore(DDrawSurface);
  CScoreManager::DrawToSurface(self);
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
