// [COMPLEX] COM vtable call pattern — left wrapped
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int CDisplay_BltInk(CDisplay* self, struct tagRECT *a2)
{
  int v3;
  int v4;
  uint8_t v6[8];
  int v7[3];
  int v8;

  v7[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v6), "CDisplay::BltInk", 0);
  v8 = 0;
  if ( *((uint32_t *)self + 3) && (v3 = *((uint32_t *)self + 5)) != 0 )
  {
    v7[0] = (*(int (__stdcall **)(uint32_t, struct tagRECT *, int, struct tagRECT *, int, uint32_t))(**((uint32_t **)self + 3)
                                                                                                + 20))(
              *((uint32_t *)self + 3),
              a2,
              v3,
              a2,
              0x1000000,
              0);
    v4 = v7[0];
  }
  else
  {
    v4 = -2147467261;
    v7[0] = -2147467261;
  }
  v8 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v6)->~CLogBlock();
  return v4;
}