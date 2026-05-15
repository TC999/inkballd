#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "global_types.h"

extern void __stdcall NormalizeRect(struct tagRECT* rect);

BOOL __stdcall PointInRect(LONG a1, LONG a2, struct tagRECT *a3)
{
  BOOL v3;
  uint8_t v5[16];
  int v6;

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "PointInRect", 0);
  v6 = 0;
  NormalizeRect(a3);
  v3 = a1 >= a3->left && a1 < a3->right && a2 >= a3->top && a2 < a3->bottom;
  v6 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return v3;
}
