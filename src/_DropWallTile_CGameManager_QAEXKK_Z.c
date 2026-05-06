void __thiscall CGameManager::DropWallTile(CGameManager *this, void *a2, unsigned int a3)
{
  bool v3; // cc
  struct CBoardTile *Tile; // eax
  struct CBoardTile *v5; // esi
  char *BitmapRect; // eax
  CBoardTile *v7; // edi
  double v8; // st7
  _BYTE v9[20]; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+24h] [ebp-4h]
  CBoardTile *v11; // [esp+30h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameManager::DropWallTile", 0);
  v3 = (unsigned int)a2 <= *((_DWORD *)g_pCGameBoard + 2467);
  v10 = 0;
  if ( !v3
    && (unsigned int)a2 < *((_DWORD *)g_pCGameBoard + 2465)
    && a3 > *((_DWORD *)g_pCGameBoard + 2468)
    && a3 < *((_DWORD *)g_pCGameBoard + 2466) )
  {
    Tile = CGameBoard::GetTile(g_pCGameBoard, (int)a2, a3);
    v5 = Tile;
    if ( !*((_DWORD *)Tile + 17)
      && !CGameBoard::BallOnTile(g_pCGameBoard, Tile)
      && CTileManager::GetTileCount(*((CTileManager **)g_pCGameBoard + 2478)) )
    {
      LOBYTE(v10) = 1;
      v11 = (CBoardTile *)operator new(0x58u);
      LOBYTE(v10) = 2;
      if ( v11 )
      {
        BitmapRect = CGameBoard::GetBitmapRect(37);
        v7 = CBoardTileWall::CBoardTileWall(v11, *((_DWORD *)v5 + 19), *((_DWORD *)v5 + 20), (int)BitmapRect, 0);
      }
      else
      {
        v7 = 0;
      }
      *((_DWORD *)v7 + 6) = *((_DWORD *)v5 + 6);
      *((_DWORD *)v7 + 7) = *((_DWORD *)v5 + 7);
      *((double *)v7 + 1) = *((double *)v5 + 1);
      v8 = *((double *)v5 + 2);
      v10 = 0;
      *((double *)v7 + 2) = v8;
      CGameBoard::SetTile(g_pCGameBoard, v7);
      CGameBoard::ShadowizeTile((CInk **)g_pCGameBoard, v7, 1);
    }
  }
  v10 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
}
