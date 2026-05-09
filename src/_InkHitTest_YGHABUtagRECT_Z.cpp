#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall InkHitTest(const struct tagRECT *a1)
{
  LONG left; // esi
  int v2; // eax
  int v3; // edi
  LONG v4; // eax
  LONG top; // esi
  int v6; // eax
  int v7; // esi
  uint8_t v9[8]; // [esp+10h] [ebp-1Ch] BYREF
  int v11; // [esp+28h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "InkHitTest", 0);
  left = a1->left;
  v2 = a1->right - a1->left;
  v11 = 0;
  v3 = v2 / 2;
  v4 = v2 / 2 + left;
  top = a1->top;
  v10.x = v4;
  v10.y = top + (a1->bottom - top) / 2;
  if ( !v3 )
    v3 = 1;
  v6 = CInk::HitCircleTest(*((CInk **)g_pCGameBoard + 2481), &v10, v3, 0);
  v11 = -1;
  v7 = v6;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return v7;
}
