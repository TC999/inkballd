#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int __stdcall InkHitTest(const struct tagRECT *a1)
{
    uint32_t v10;
    tagPOINT v10_pt;
  LONG left;
  int v2;
  int v3;
  LONG v4;
  LONG top;
  int v6;
  int v7;
  uint8_t v9[8];
  int v11;

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "InkHitTest", 0);
  left = a1->left;
  v2 = a1->right - a1->left;
  v11 = 0;
  v3 = v2 / 2;
  v4 = v2 / 2 + left;
  top = a1->top;
  v10_pt.x = v4;
  v10_pt.y = top + (a1->bottom - top) / 2;
  if ( !v3 )
    v3 = 1;
  v6 = CInk_HitCircleTest(*((CInk **)g_pCGameBoard + 2481), &v10_pt, v3, 0);
  v11 = -1;
  v7 = v6;
  ((Helpers::CLogBlock*)v9)->~CLogBlock();
  return v7;
}

