#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int Blt_CDisplay(CDisplay *self,
        uint32_t a2,
        uint32_t a3,
        void* a4,
        void* a5,
        uint32_t a6)
{
  int v7;
  int v8;
  uint8_t v10[8];
  int v11[3];
  int v12;

  v11[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CDisplay::Blt", v11);
  v12 = 0;
  if ( *((uint32_t *)self + 3) )
    v7 = (*(int (__stdcall **)(uint32_t, uint32_t, uint32_t, struct IDirectDrawSurface7 *, struct tagRECT *, uint32_t))(**((uint32_t **)self + 3) + 28))(
           *((uint32_t *)self + 3),
           a2,
           a3,
           (IDirectDrawSurface7*)a4,
           (tagRECT*)a5,
           a6);
  else
    v7 = -2147467261;
  v12 = -1;
  v8 = v7;
  v11[0] = v7;
  ((Helpers::CLogBlock*)v10)->~CLogBlock();
  return v8;
}

