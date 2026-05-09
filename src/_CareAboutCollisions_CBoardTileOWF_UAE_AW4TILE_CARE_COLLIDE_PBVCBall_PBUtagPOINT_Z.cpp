#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CBoardTileOWF::CareAboutCollisions(int*this, CBoardObject *a2, int*a3)
{
  int v4; // eax
  int v5; // ecx
  bool v6; // c0
  bool v7; // c0
  bool v8; // c3
  int v9; // esi
  int v10; // esi
  uint8_t v14[8]; // [esp+28h] [ebp-1Ch] BYREF
  int v16; // [esp+40h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CBoardTileOWF::CareAboutCollisions", 0);
  v16 = 0;
  CBoardObject::GetCenterPoint((CBoardObject *)this, &v13);
  CBoardObject::GetCenterPoint(a2, &v15);
  CBoardObject::GetBoundingRect((CBoardObject *)this, &v12);
  v4 = (int)((double)this[6] / 1.6);
  v5 = this[22];
  if ( !v5 )
  {
    v12.bottom -= v4;
    if ( v15.y < (v12.bottom + v12.top) / 2 )
    {
      v6 = *((double *)a2 + 9) > 0.0;
      goto LABEL_4;
    }
LABEL_16:
    v9 = this[11];
    if ( v9 && v9 != *((uint32_t *)a2 + 11) && (!a3 || PointInRect(*a3, a3[1], &v12)) )
      goto LABEL_20;
LABEL_22:
    v10 = 0;
    goto LABEL_21;
  }
  if ( v5 == 1 )
  {
    v12.top += v4;
    if ( v15.y <= (v12.top + v12.bottom) / 2 )
      goto LABEL_16;
    v7 = *((double *)a2 + 9) > 0.0;
    v8 = 0.0 == *((double *)a2 + 9);
LABEL_15:
    if ( !v7 && !v8 )
      goto LABEL_20;
    goto LABEL_16;
  }
  if ( v5 != 2 )
  {
    if ( v5 != 3 )
      goto LABEL_22;
    v12.left += v4;
    if ( v15.x <= (v12.left + v12.right) / 2 )
      goto LABEL_16;
    v7 = *((double *)a2 + 8) > 0.0;
    v8 = 0.0 == *((double *)a2 + 8);
    goto LABEL_15;
  }
  v12.right -= v4;
  if ( v15.x >= (v12.right + v12.left) / 2 )
    goto LABEL_16;
  v6 = *((double *)a2 + 8) > 0.0;
LABEL_4:
  if ( !v6 )
    goto LABEL_16;
LABEL_20:
  v10 = 2;
LABEL_21:
  v16 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v10;
}
