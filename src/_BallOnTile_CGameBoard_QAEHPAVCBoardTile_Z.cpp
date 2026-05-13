// [COMPLEX] Undeclared variables (v7, v8, RectIntersectsRect), goto — left wrapped
#if 0
#include "global_types.h"
#include <cstdint>
int CGameBoard_BallOnTile(CGameBoard* self, CBoardTile* a2)
{
  int v3;
  CBoardObject **v4;
  int v5;
  uint8_t v9[16];
  int v10;

  v3 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v9), "CGameBoard::BallOnTile", 0);
  v10 = 0;
  CBoardObject::GetBoundingRect(a2, &v8);
  if ( *((int*)self + 656) <= 0 )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    v4 = (CBoardObject **)(reinterpret_cast<char*>(self) + 2628);
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
      if ( v3 >= *((uint32_t *)self + 656) )
        goto LABEL_6;
    }
    v5 = 1;
  }
  v10 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v9)->~CLogBlock();
  return v5;
}

#endif