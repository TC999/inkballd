#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CBoardTileBumper::CareAboutCollisions(CBoardObject *this, CBoardObject *a2, int*a3)
{
  int v4; // eax
  int v5; // ecx
  int v6; // esi
  int*v7; // ecx
  int v8; // esi
  int v9; // esi
  uint8_t v14[16]; // [esp+30h] [ebp-14h] BYREF
  int v15; // [esp+40h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CBoardTileBumper::CareAboutCollisions", 0);
  v15 = 0;
  CBoardObject::GetCenterPoint(this, &v13);
  CBoardObject::GetCenterPoint(a2, &v12);
  CBoardObject::GetBoundingRect(this, &v11);
  v4 = *((uint32_t *)this + 6) / 3;
  v5 = *((uint32_t *)this + 22);
  if ( v5 )
  {
    if ( v5 != 2 )
      goto LABEL_14;
    v8 = *((uint32_t *)this + 11);
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
    v6 = *((uint32_t *)this + 11);
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

#endif
