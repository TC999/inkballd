#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
BOOL __stdcall RectIntersectsRect(struct tagRECT *a1, struct tagRECT *a2)
{
  BOOL v3; // esi
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "RectIntersectsRect", 0);
  v5 = 0;
  NormalizeRect(a1);
  NormalizeRect(a2);
  if ( PointInRect(a1->left, a1->top, a2)
    || PointInRect(a1->right, a1->top, a2)
    || PointInRect(a1->left, a1->bottom, a2) )
  {
    v5 = -1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
    return 1;
  }
  else
  {
    v3 = PointInRect(a1->right, a1->bottom, a2);
    v5 = -1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
    return v3;
  }
}
