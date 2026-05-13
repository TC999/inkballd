#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
CBoardTile*__stdcall CheckForBallCollisionWithNonDeflectingTile(CBall*a1)
{
    uint32_t v10;
    uint32_t v13;
    uint32_t v16;
    uint32_t v7;
  int v1; // ebx
  int v2; // edi
  CBoardObject *v3; // esi
  long double v4; // st7
  CBoardTile *v5; // esi
  CBoardObject *v9[4]; // [esp+40h] [ebp-54h]
  uint8_t v11[8]; // [esp+60h] [ebp-34h] BYREF
  long double v12; // [esp+68h] [ebp-2Ch]
  int v15; // [esp+80h] [ebp-14h]
  int v17; // [esp+90h] [ebp-4h]

  v1 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CheckForBallCollisionWithNonDeflectingTile", 0);
  v12 = 1.797693134862316e308;
  v17 = 0;
  v2 = -1;
  CBoardObject::GetCenterPoint(a1, &v13);
  CBoardObject::GetBoundingRect(a1, &v10);
  v9[0] = CGameBoard::GetTile(g_pCGameBoard, v10.left, v10.top);
  v9[1] = CGameBoard::GetTile(g_pCGameBoard, v10.right, v10.top);
  v9[2] = CGameBoard::GetTile(g_pCGameBoard, v10.left, v10.bottom);
  v9[3] = CGameBoard::GetTile(g_pCGameBoard, v10.right, v10.bottom);
  v16 = v7;
  do
  {
    uint32_t v10; // auto-declared
    uint32_t v13; // auto-declared
    uint32_t v14; // auto-declared
    uint32_t v16; // auto-declared
    uint32_t v7; // auto-declared
    uint32_t v8; // auto-declared
    v3 = v9[v1];
    if ( (*(int (__thiscall **)(CBoardObject *, CBall*, uint32_t))(*(uint32_t *)v3 + 8))(v3, a1, 0) == 1 )
    {
      CBoardObject::GetBoundingRect(v3, &v8);
      if ( CBall::VerifyCollision(a1, &v8, v16) )
      {
        CBoardObject::GetCenterPoint(v3, &v14);
        v15 = v14.y - v13.y;
        v4 = sqrt((double)(v14.x - v13.x) * (double)(v14.x - v13.x) + (double)(v14.y - v13.y) * (double)(v14.y - v13.y));
        if ( v12 > v4 )
        {
          v12 = v4;
          v2 = v1;
        }
      }
    }
    ++v16;
    ++v1;
  }
  while ( v1 < 4 );
  if ( v2 == -1 )
  {
    v5 = 0;
  }
  else
  {
    v5 = v9[v2];
    CBoardTile::SetClosestSide(v5, &v7[v2]);
    (*(void (__thiscall **)(CBoardTile *, CBall*))(*(uint32_t *)v5 + 4))(v5, a1);
  }
  v17 = -1;
  ((Helpers::CLogBlock*)v11)->~CLogBlock();
  return v5;
}

