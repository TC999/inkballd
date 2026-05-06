void __stdcall ConvertTileToFloor(struct CBoardTileBreakWall *a1)
{
  struct CBoardTile *v2; // eax
  char *BitmapRect; // eax
  CBoardObject *v4; // eax
  struct CBoardTile *v5; // ebx
  _BYTE v6[20]; // [esp+10h] [ebp-18h] BYREF
  int v7; // [esp+24h] [ebp-4h]
  CBoardObject *v8; // [esp+30h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "ConvertTileToFloor", 0);
  v2 = (struct CBoardTile *)*((_DWORD *)a1 + 22);
  v7 = 0;
  if ( v2 )
  {
    v5 = v2;
    goto LABEL_8;
  }
  LOBYTE(v7) = 1;
  v8 = (CBoardObject *)operator new(0x58u);
  LOBYTE(v7) = 2;
  if ( v8 )
  {
    BitmapRect = CGameBoard::GetBitmapRect(0);
    v4 = CBoardTile::CBoardTile(v8, 0, *((_DWORD *)a1 + 19), *((_DWORD *)a1 + 20), (int)BitmapRect);
  }
  else
  {
    v4 = 0;
  }
  v5 = v4;
  v7 = 0;
  if ( v4 )
  {
    *((_DWORD *)v4 + 6) = *((_DWORD *)g_pCGameBoard + 2472);
    *((_DWORD *)v4 + 7) = *((_DWORD *)g_pCGameBoard + 2472);
    *((double *)v4 + 1) = *((double *)a1 + 1);
    *((double *)v4 + 2) = *((double *)a1 + 2);
LABEL_8:
    operator delete(a1);
    CGameBoard::SetTile(g_pCGameBoard, v5);
    CGameBoard::ShadowizeTile((CInk **)g_pCGameBoard, v5, 0);
  }
  v7 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
}
