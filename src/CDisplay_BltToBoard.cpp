// [COMPLEX] COM vtable call, missing parameter a5 — left wrapped
#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int CDisplay_BltToBoard(
        CDisplay* self,
        uint32_t a2,
        uint32_t a3,
        CSurface* a4,
        struct tagRECT* a5)
{
  int IsColorKeyed;
  int v7;
  int v9;
  int v10;
  BOOL v12;
  uint8_t v13[8];
  int v14[3];
  int v15;

  v14[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v13), "CDisplay::BltToBoard", 0);
  v15 = 0;
  if ( !a4 )
    v14[0] = -2147024809;
  IsColorKeyed = CSurface::IsColorKeyed(a4);
  v7 = **((uint32_t **)self + 6);
  v12 = IsColorKeyed != 0;
  DDrawSurface = CSurface::GetDDrawSurface(a4);
  v9 = (*(int (__stdcall **)(uint32_t, uint32_t, uint32_t, struct IDirectDrawSurface7 *, struct tagRECT *, BOOL))(v7 + 28))(
         *((uint32_t *)self + 6),
         a2,
         a3,
         DDrawSurface,
         a5,
         v12);
  v15 = -1;
  v14[0] = v9;
  v10 = v9;
  reinterpret_cast<Helpers::CLogBlock*>(v13)->~CLogBlock();
  return v10;
}

#endif