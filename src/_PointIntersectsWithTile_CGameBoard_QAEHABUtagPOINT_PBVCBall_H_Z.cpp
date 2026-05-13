#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
BOOL CGameBoard::PointIntersectsWithTile(
        CGameBoard *this,
        const struct tagPOINT *a2,
        const CBall*a3,
        int a4)
{
  CBoardTile*Tile; // esi
  int v7; // eax
  BOOL v8; // esi
  LONG y; // [esp-4h] [ebp-28h]
  uint8_t v10[16]; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v10), "CGameBoard::PointIntersectsWithTile", 0);
  y = a2->y;
  v11 = 0;
  Tile = CGameBoard::GetTile(this, a2->x, y);
  if ( (*(int (**)(CBoardTile*, const CBall*, const struct tagPOINT *))(*(uint32_t *)Tile + 8))(
         Tile,
         a3,
         a2) )
  {
    v7 = (*(int (**)(CBoardTile*, const CBall*, const struct tagPOINT *))(*(uint32_t *)Tile + 8))(
           Tile,
           a3,
           a2);
    v8 = 1;
    if ( v7 == 1 )
      v8 = a4 == 0;
    v11 = -1;
    reinterpret_cast<Helpers::CLogBlock*>(v10)->~CLogBlock();
    return v8;
  }
  else
  {
    v11 = -1;
    reinterpret_cast<Helpers::CLogBlock*>(v10)->~CLogBlock();
    return 0;
  }
}

#endif
