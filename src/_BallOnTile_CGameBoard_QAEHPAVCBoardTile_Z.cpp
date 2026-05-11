#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CGameBoard::BallOnTile(CGameBoard *this, CBoardTile*a2)
{
  int v3; // ebx
  CBoardObject **v4; // edi
  int v5; // esi
  uint8_t v9[16]; // [esp+30h] [ebp-14h] BYREF
  int v10; // [esp+40h] [ebp-4h]

  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameBoard::BallOnTile", 0);
  v10 = 0;
  CBoardObject::GetBoundingRect(a2, &v8);
  if ( *((int*)this + 656) <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = (CBoardObject **)(reinterpret_cast<char*>(this) + 2628);
    while ( 1 )
    {
      if ( *((uint32_t *)*v4 + 39) )
      {
        CBoardObject::GetBoundingRect(*v4, &v7);
        if ( RectIntersectsRect(&v7, &v8) )
          break;
      }
      ++v3;
      ++v4;
      if ( v3 >= *((uint32_t *)this + 656) )
        goto LABEL_6;
    }
    v5 = 1;
  }
  v10 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v9)->~CLogBlock();
  return v5;
}

#endif
