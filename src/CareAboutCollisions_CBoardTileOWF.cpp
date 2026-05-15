// [COMPLEX] Undeclared CBoardObject methods, undeclared v12/v13/v15 — left wrapped
#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int CBoardTileOWF_CareAboutCollisions(int* self, CBoardObject* a2, int* a3)
{
  int v4;
  int v5;
  bool v6;
  bool v7;
  bool v8;
  int v9;
  int v10;
  uint8_t v14[8];
  int v16;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v14), "CBoardTileOWF::CareAboutCollisions", 0);
  v16 = 0;
  CBoardObject::GetCenterPoint((CBoardObject *)self, &v13);
  CBoardObject::GetCenterPoint(a2, &v15);
  CBoardObject::GetBoundingRect((CBoardObject *)self, &v12);
  v4 = (int)((double)self[6] / 1.6);
  v5 = self[22];
  if ( !v5 )
  {
    v12.bottom -= v4;
    if ( v15.y < (v12.bottom + v12.top) / 2 )
    {
      v6 = *((double *)a2 + 9) > 0.0;
      goto LABEL_4;
    }
LABEL_16:
    v9 = self[11];
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
  reinterpret_cast<Helpers::CLogBlock*>(v14)->~CLogBlock();
  return v10;
}

#endif
