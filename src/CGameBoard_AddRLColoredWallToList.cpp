//----- (01008213) --------------------------------------------------------
void CGameBoard::AddRLColoredWallToList(CGameBoard *self, struct CBoardTileRLColored *a2)
{
  int v3; // ecx
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddRLColoredWallToList", 0);
  v3 = *((_DWORD *)self + 366);
  if ( v3 < 289 )
  {
    *((_DWORD *)self + v3 + 367) = (uint32)(uintptr_t)a2;
    ++*((_DWORD *)self + 366);
  }
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
}
