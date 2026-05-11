#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CScoreManager::Restore(CScoreManager *this)
{
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CScoreManager::Restore", 0);
  v4 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  DDrawSurface->lpVtbl->Restore(DDrawSurface);
  (*(void (__thiscall **)(CScoreManager *))(*(uint32_t *)this + 4))(this);
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}

#endif
