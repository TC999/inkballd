// [COMPLEX] Many undeclared constructors, duplicate code blocks — left wrapped
#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>
CBoardTile*__stdcall BuildTileObject(int a1, int a2, int a3)
{
  uint32_t v4; // ebx
  char*v5; // eax
  CBoardObject *v6; // esi
  int v7; // ecx
  uint32_t v8; // edi
  uint32_t v9; // esi
  char*v10; // eax
  CBoardTile *v11; // eax
  double v12; // st7
  uint32_t v13; // esi
  char*v14; // eax
  uint32_t v15; // esi
  char*v16; // eax
  uint32_t v17; // edi
  uint32_t v18; // esi
  char*v19; // eax
  uint32_t v20; // edi
  int v21; // ebx
  int v22; // esi
  void*v23; // ecx
  uint32_t v24; // ebx
  uint32_t v25; // esi
  void*v26; // ecx
  uint32_t v27; // esi
  char*v28; // eax
  uint32_t v29; // edi
  uint32_t v30; // esi
  char*v31; // eax
  char*BitmapRect; // eax
  CBoardObject *v33; // edi
  int v34; // ecx
  uint32_t v35; // ecx
  double v36; // st7
  double v37; // st7
  uint8_t v39[8]; // [esp+18h] [ebp-20h] BYREF
  void*v40; // [esp+20h] [ebp-18h]
  int v41; // [esp+24h] [ebp-14h]
  int v42; // [esp+34h] [ebp-4h]
  CBoardObject *v43; // [esp+40h] [ebp+8h]
  CBoardTile *v44; // [esp+40h] [ebp+8h]
  CBoardTile *v45; // [esp+40h] [ebp+8h]
  CBoardTile *v46; // [esp+40h] [ebp+8h]
  CBoardTile *v47; // [esp+40h] [ebp+8h]
  char*v48; // [esp+40h] [ebp+8h]
  char*v49; // [esp+40h] [ebp+8h]
  CBoardTile *v50; // [esp+40h] [ebp+8h]
  CBoardTile *v51; // [esp+40h] [ebp+8h]
  CBoardObject *v52; // [esp+40h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v39), "BuildTileObject", 0);
  v4 = (a1 >> 12) & 0xF;
  v42 = 0;
  if ( v4 > 0xA )
    goto LABEL_17;
  if ( !v4 || v4 == 9 )
  {
    LOBYTE(v42) = 1;
    v52 = (CBoardObject *)operator new(0x58u);
    LOBYTE(v42) = 2;
    if ( v52 )
    {
      BitmapRect = CGameBoard::GetBitmapRect(0);
      v33 = CBoardTile::CBoardTile(v52, 0, a2, a3, (int)BitmapRect);
    }
    else
    {
      v33 = 0;
    }
    *((uint32_t *)v33 + 9) = 0;
    *((uint32_t *)v33 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
    *((uint32_t *)v33 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
    v34 = *((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472);
    v42 = 0;
    *((double *)v33 + 1) = (double)v34;
    *((double *)v33 + 2) = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
    if ( v4 == 9 )
    {
      v35 = a1 & 0xF;
      if ( v35 > 4 )
        goto LABEL_17;
      v36 = (double)(((a1 >> 4) & 0xF) + 16 * ((a1 >> 8) & 0xF));
      if ( 255.0 == v36 )
      {
        v37 = -1.0;
      }
      else
      {
        if ( v36 < 0.0 || v36 > 31.0 )
          goto LABEL_17;
        v37 = v36 * 11.25;
      }
      AddAliveBallToBoard(v35, v33, v37);
    }
    v6 = v33;
    goto LABEL_75;
  }
  if ( v4 != 1 )
  {
    switch ( v4 )
    {
      case 2u:
        v8 = a1 & 0xF;
        if ( v8 <= 4 )
        {
          v9 = (a1 >> 4) & 0xF;
          if ( v9 <= 3 )
          {
            LOBYTE(v42) = 7;
            v44 = (CBoardTile *)operator new(0x58u);
            LOBYTE(v42) = 8;
            if ( v44 )
            {
              v10 = CGameBoard::GetBitmapRect(v9 + 4 * v8 + 17);
              v11 = CBoardTileDrain::CBoardTileDrain(v44, v9 + 2, a2, a3, (int)v10, v8);
            }
            else
            {
              v11 = 0;
            }
            *((uint32_t *)v11 + 9) = v9 + 4 * v8 + 17;
            *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
            *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
            *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
            v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
LABEL_16:
            *((double *)v11 + 2) = v12;
            v6 = v11;
            goto LABEL_75;
          }
        }
        break;
      case 3u:
        v13 = a1 & 0xF;
        if ( v13 <= 4 )
        {
          LOBYTE(v42) = 10;
          v45 = (CBoardTile *)operator new(0x58u);
          LOBYTE(v42) = 11;
          if ( v45 )
          {
            v14 = CGameBoard::GetBitmapRect(v13 + 37);
            v11 = CBoardTileWall::CBoardTileWall(v45, a2, a3, (int)v14, v13);
          }
          else
          {
            v11 = 0;
          }
          *((uint32_t *)v11 + 9) = v13 + 37;
          *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
          *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
          *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
          v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
          goto LABEL_16;
        }
        break;
      case 4u:
        v15 = a1 & 0xF;
        if ( v15 <= 4 )
        {
          LOBYTE(v42) = 13;
          v46 = (CBoardTile *)operator new(0x60u);
          LOBYTE(v42) = 14;
          if ( v46 )
          {
            v16 = CGameBoard::GetBitmapRect(v15 + 42);
            v11 = CBoardTileBreakWall::CBoardTileBreakWall(v46, a2, a3, (int)v16, v15);
          }
          else
          {
            v11 = 0;
          }
          *((uint32_t *)v11 + 9) = v15 + 42;
          *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
          *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
          *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
          v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
          goto LABEL_16;
        }
        break;
      case 5u:
        v17 = a1 & 0xF;
        if ( v17 <= 4 )
        {
          v18 = (a1 >> 4) & 0xF;
          if ( v18 <= 3 )
          {
            LOBYTE(v42) = 16;
            v47 = (CBoardTile *)operator new(0x60u);
            LOBYTE(v42) = 17;
            if ( v47 )
            {
              v19 = CGameBoard::GetBitmapRect(5 * v18 + v17 + 47);
              v11 = CBoardTileOWF::CBoardTileOWF(v47, a2, a3, (int)v19, v17, v18);
            }
            else
            {
              v11 = 0;
            }
            *((uint32_t *)v11 + 9) = 5 * v18 + v17 + 47;
            *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
            *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
            *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
            v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
            goto LABEL_16;
          }
        }
        break;
      case 6u:
        v20 = a1 & 0xF;
        if ( v20 <= 4 )
        {
          v21 = (a1 >> 8) & 0xF;
          v22 = (a1 >> 4) & 0xF;
          v41 = 5 * v20 + 77;
          v48 = CGameBoard::GetBitmapRect(v41);
          LOBYTE(v42) = 19;
          v23 = operator new(0x70u);
          v40 = v23;
          LOBYTE(v42) = 20;
          if ( v23 )
            v11 = CBoardTileRLGray::CBoardTileRLGray(
                    (CBoardTile *)v23,
                    a2,
                    a3,
                    (int)v48,
                    0,
                    v20,
                    1000 * (v21 + 1) / 2,
                    1000 * (v22 + 1) / 2);
          else
            v11 = 0;
          *((uint32_t *)v11 + 9) = v41;
          *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
          *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
          *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
          v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
          goto LABEL_16;
        }
        break;
      case 7u:
        v24 = a1 & 0xF;
        if ( v24 <= 4 )
        {
          v25 = (a1 >> 4) & 0xF;
          if ( v25 <= 4 )
          {
            v49 = CGameBoard::GetBitmapRect(5 * v25 + v24 + 77);
            LOBYTE(v42) = 22;
            v26 = operator new(0x60u);
            v40 = v26;
            LOBYTE(v42) = 23;
            if ( v26 )
              v11 = CBoardTileRLColored::CBoardTileRLColored((CBoardTile *)v26, a2, a3, (int)v49, v24, v25);
            else
              v11 = 0;
            *((uint32_t *)v11 + 9) = 5 * v25 + v24 + 77;
            *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
            *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
            *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
            v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
            goto LABEL_16;
          }
        }
        break;
      case 8u:
        v27 = (a1 >> 4) & 0xF;
        if ( v27 <= 3 )
        {
          LOBYTE(v42) = 25;
          v50 = (CBoardTile *)operator new(0x60u);
          LOBYTE(v42) = 26;
          if ( v50 )
          {
            v28 = CGameBoard::GetBitmapRect(v27 + 102);
            v11 = CBoardTileChevron::CBoardTileChevron(v50, a2, a3, (int)v28, v27);
          }
          else
          {
            v11 = 0;
          }
          *((uint32_t *)v11 + 9) = v27 + 102;
          *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
          *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
          *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
          v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
          goto LABEL_16;
        }
        break;
      default:
        v29 = a1 & 0xF;
        if ( v29 <= 4 )
        {
          v30 = (a1 >> 4) & 0xF;
          if ( v30 <= 1 )
          {
            LOBYTE(v42) = 28;
            v51 = (CBoardTile *)operator new(0x60u);
            LOBYTE(v42) = 29;
            if ( v51 )
            {
              v31 = CGameBoard::GetBitmapRect(5 * v30 + v29 + 67);
              v11 = CBoardTileBumper::CBoardTileBumper(v51, a2, a3, (int)v31, v29, 2 * v30);
            }
            else
            {
              v11 = 0;
            }
            *((uint32_t *)v11 + 9) = 5 * v30 + v29 + 67;
            *((uint32_t *)v11 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
            *((uint32_t *)v11 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
            *((double *)v11 + 1) = (double)(*((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472));
            v12 = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
            goto LABEL_16;
          }
        }
        break;
    }
LABEL_17:
    DisplayBoardLoadMsg();
  }
  LOBYTE(v42) = 4;
  v43 = (CBoardObject *)operator new(0x58u);
  LOBYTE(v42) = 5;
  if ( v43 )
  {
    v5 = CGameBoard::GetBitmapRect(1);
    v6 = CBoardTile::CBoardTile(v43, 1, a2, a3, (int)v5);
  }
  else
  {
    v6 = 0;
  }
  *((uint32_t *)v6 + 9) = 1;
  *((uint32_t *)v6 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
  *((uint32_t *)v6 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
  v7 = *((uint32_t *)g_pCGameBoard + 2467) + a2 * *((uint32_t *)g_pCGameBoard + 2472);
  v42 = 0;
  *((double *)v6 + 1) = (double)v7;
  *((double *)v6 + 2) = (double)(*((uint32_t *)g_pCGameBoard + 2468) + a3 * *((uint32_t *)g_pCGameBoard + 2472));
  CBallManager::AddBallGenerator(*((CBallManager **)g_pCGameBoard + 2476), v6);
LABEL_75:
  v42 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v39)->~CLogBlock();
  return v6;
}

#endif