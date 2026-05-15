#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern "C" {
    char* __stdcall GetBitmapRect(int a1);
}

void DropWallTile_CGameManager(CGameManager* self, uint32_t a3)
{
  bool v3; // cc
  CBoardTile*Tile; // eax
  CBoardTile*v5; // esi
  char*BitmapRect; // eax
  CBoardTile *v7; // edi
  double v8; // st7
  uint8_t v9[20]; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+24h] [ebp-4h]
  CBoardTile *v11; // [esp+30h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)v9, "CGameManager::DropWallTile", 0);
  v3 = a3 <= *((uint32_t *)g_pCGameBoard + 2467);
  v10 = 0;
  if ( !v3
    && a3 < *((uint32_t *)g_pCGameBoard + 2465)
    && a3 > *((uint32_t *)g_pCGameBoard + 2468)
    && a3 < *((uint32_t *)g_pCGameBoard + 2466) )
  {
    Tile = CGameBoard::GetTile(g_pCGameBoard, (int)self, a3);
    v5 = Tile;
    if ( !*((uint32_t *)Tile + 17)
      && !CGameBoard::BallOnTile(g_pCGameBoard, Tile)
      && CTileManager::GetTileCount(*((CTileManager **)g_pCGameBoard + 2478)) )
    {
      LOBYTE(v10) = 1;
      v11 = (CBoardTile *)operator new(0x58u);
      LOBYTE(v10) = 2;
      if ( v11 )
      {
        BitmapRect = GetBitmapRect(37);
        v7 = (CBoardTile*)operator new(0x58u);
        if (v7) { memset(v7, 0, 0x58); }
      }
      else
      {
        v7 = 0;
      }
      *((uint32_t *)v7 + 6) = *((uint32_t *)v5 + 6);
      *((uint32_t *)v7 + 7) = *((uint32_t *)v5 + 7);
      *((double *)v7 + 1) = *((double *)v5 + 1);
      v8 = *((double *)v5 + 2);
      v10 = 0;
      *((double *)v7 + 2) = v8;
      CGameBoard::SetTile(g_pCGameBoard, v7);
      CGameBoard::ShadowizeTile(g_pCGameBoard, v7, 1);
    }
  }
  v10 = -1;
  ((Helpers::CLogBlock*)v9)->~CLogBlock();
}
