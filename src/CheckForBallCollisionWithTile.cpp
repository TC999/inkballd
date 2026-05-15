#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cfloat>
#include <windows.h>
CBoardTile*__stdcall CheckForBallCollisionWithTile(CBall*a1)
{
    RECT v8;
    RECT v15;
    POINT v12;
    POINT v13;
    uint32_t v7[8];
    uint32_t v10[8];
  int v1; // edi
  int v2; // ebx
  CBoardObject *v3; // esi
  long double v4; // st7
  CBoardTile *v5; // esi
  uint8_t v9[8]; // [esp+40h] [ebp-70h] BYREF
  CBoardObject *v11[4]; // [esp+68h] [ebp-48h]
  long double v14; // [esp+88h] [ebp-28h]
  int v16; // [esp+A0h] [ebp-10h]
  int v17; // [esp+ACh] [ebp-4h]

  v1 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CheckForBallCollisionWithTile", 0);
  v14 = DBL_MAX;
  v17 = 0;
  v2 = -1;
  CBoardObject::GetCenterPoint(a1, &v12);
  CBoardObject::GetBoundingRect(a1, &v15);
  v11[0] = (CBoardObject*)CGameBoard::GetTile(g_pCGameBoard, v15.left, v15.top);
  v10[0] = v15.left;
  v10[1] = v15.top;
  v11[1] = (CBoardObject*)CGameBoard::GetTile(g_pCGameBoard, v15.right, v15.top);
  v10[2] = v15.right;
  v10[3] = v15.top;
  v11[2] = (CBoardObject*)CGameBoard::GetTile(g_pCGameBoard, v15.left, v15.bottom);
  v10[4] = v15.left;
  v10[5] = v15.bottom;
  v11[3] = (CBoardObject*)CGameBoard::GetTile(g_pCGameBoard, v15.right, v15.bottom);
  v10[6] = v15.right;
  v10[7] = v15.bottom;
  do
  {
    v3 = v11[v1];
    if ( (*(int (__thiscall **)(CBoardObject *, CBall*, uint32_t *))(*(uint32_t *)v3 + 8))(v3, a1, &v10[2 * v1]) == 2 )
    {
      CBoardObject::GetBoundingRect(v3, &v8);
      if ( CBall::VerifyCollision(a1, &v8, (void*)&v7[v1]) )
      {
        CBoardObject::GetCenterPoint(v3, &v13);
        v16 = v13.y - v12.y;
        v4 = sqrt((double)(v13.x - v12.x) * (double)(v13.x - v12.x) + (double)(v13.y - v12.y) * (double)(v13.y - v12.y));
        if ( v14 > v4 )
        {
          v14 = v4;
          v2 = v1;
        }
      }
    }
    ++v1;
  }
  while ( v1 < 4 );
  if ( v2 == -1 )
  {
    v5 = 0;
  }
  else
  {
    v5 = (CBoardTile*)v11[v2];
    CBoardTile::SetClosestSide(v5, (void*)&v7[v2]);
    (*(void (__thiscall **)(CBoardTile *, CBall*))(*(uint32_t *)v5 + 4))(v5, a1);
  }
  v17 = -1;
  ((Helpers::CLogBlock*)v9)->~CLogBlock();
  return v5;
}
