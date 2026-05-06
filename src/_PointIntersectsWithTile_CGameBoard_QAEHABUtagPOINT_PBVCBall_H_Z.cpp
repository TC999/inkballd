BOOL __thiscall CGameBoard::PointIntersectsWithTile(
        CGameBoard *this,
        const struct tagPOINT *a2,
        const struct CBall *a3,
        int a4)
{
  struct CBoardTile *Tile; // esi
  int v7; // eax
  BOOL v8; // esi
  LONG y; // [esp-4h] [ebp-28h]
  _BYTE v10[16]; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::PointIntersectsWithTile", 0);
  y = a2->y;
  v11 = 0;
  Tile = CGameBoard::GetTile(this, a2->x, y);
  if ( (*(int (__thiscall **)(struct CBoardTile *, const struct CBall *, const struct tagPOINT *))(*(_DWORD *)Tile + 8))(
         Tile,
         a3,
         a2) )
  {
    v7 = (*(int (__thiscall **)(struct CBoardTile *, const struct CBall *, const struct tagPOINT *))(*(_DWORD *)Tile + 8))(
           Tile,
           a3,
           a2);
    v8 = 1;
    if ( v7 == 1 )
      v8 = a4 == 0;
    v11 = -1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
    return v8;
  }
  else
  {
    v11 = -1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
    return 0;
  }
}
