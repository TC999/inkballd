// [COMPLEX] Undeclared CBoardObject methods (GetCenterPoint, GetBoundingRect, PointInRect) — left wrapped
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int CBoardTileBumper_CareAboutCollisions(CBoardObject* self, CBoardObject* a2, int* a3)
{
  int v4;
  int v5;
  int v6;
  int* v7;
  int v8;
  int v9;
  uint8_t v14[16];
  int v15;
  RECT v11;
  POINT v12;
  POINT v13;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v14), "CBoardTileBumper::CareAboutCollisions", 0);
  v15 = 0;
  CBoardObject::GetCenterPoint(self, &v13);
  CBoardObject::GetCenterPoint(a2, &v12);
  CBoardObject::GetBoundingRect(self, &v11);
  v4 = *((uint32_t *)self + 6) / 3;
  v5 = *((uint32_t *)self + 22);
  if ( v5 )
  {
    if ( v5 != 2 )
      goto LABEL_14;
    v8 = *((uint32_t *)self + 11);
    if ( !v8 || v8 == *((uint32_t *)a2 + 11) )
      goto LABEL_14;
    v7 = a3;
    if ( a3 )
    {
      v11.left += v4;
      v11.right -= v4;
LABEL_11:
      if ( PointInRect(*v7, v7[1], &v11) )
        goto LABEL_12;
LABEL_14:
      v9 = 0;
      goto LABEL_13;
    }
  }
  else
  {
    v6 = *((uint32_t *)self + 11);
    if ( !v6 || v6 == *((uint32_t *)a2 + 11) )
      goto LABEL_14;
    v7 = a3;
    if ( a3 )
    {
      v11.top += v4;
      v11.bottom -= v4;
      goto LABEL_11;
    }
  }
LABEL_12:
  v9 = 2;
LABEL_13:
  v15 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v14)->~CLogBlock();
  return v9;
}
