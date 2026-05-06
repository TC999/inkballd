void __thiscall CGameBoard::AddRLColoredWallToList(CGameBoard *this, struct CBoardTileRLColored *a2)
{
  int v3; // ecx
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddRLColoredWallToList", 0);
  v3 = *((_DWORD *)this + 366);
  if ( v3 < 289 )
  {
    *((_DWORD *)this + v3 + 367) = a2;
    ++*((_DWORD *)this + 366);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
