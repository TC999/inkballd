#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CSurface::Create(LPDIRECTDRAWSURFACE7 *this, struct IDirectDraw7 *a2, struct _DDSURFACEDESC2 *a3)
{
  LPDIRECTDRAWSURFACE7 v6; // esi
  int v7; // esi
  char v9[8]; // [esp+10h] [ebp-18h] BYREF
  char v10[4]; // [esp+18h] [ebp-10h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  *(uint32_t *)v10 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CSurface::Create", (int*)v10);
  lpVtbl = a2->lpVtbl;
  v11 = 0;
  *(uint32_t *)v10 = lpVtbl->CreateSurface(a2, a3, this, 0);
  if ( *(int*)v10 < 0 )
  {
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x25u, &stru_1002FB8, v10[0]);
  }
  else
  {
    v5 = (struct _DDSURFACEDESC2 *)(this + 1);
    v6 = *this;
    v5->dwSize = 124;
    *(uint32_t *)v10 = v6->lpVtbl->GetSurfaceDesc(v6, v5);
    if ( *(int*)v10 < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x24u, &stru_1002FB8, v10[0]);
  }
  v7 = *(uint32_t *)v10;
  v11 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v9)->~CLogBlock();
  return v7;
}

#endif
