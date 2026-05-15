//----- (01007FD7) --------------------------------------------------------
struct CBoardTile *__thiscall CGameBoard::GetTileByIndices(CGameBoard *self, int a2, int a3)
{
  int v4; // esi
  _BYTE v6[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::GetTileByIndices", 0);
  v4 = *((_DWORD *)self + a2 + a3 * *((_DWORD *)self + 2469) + 721);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return (struct CBoardTile *)v4;
}
