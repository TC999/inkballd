struct CBoardTile *__thiscall CGameBoard::GetTile(CGameBoard *this, int a2, int a3)
{
  int v4; // esi
  _BYTE v6[8]; // [esp+8h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::GetTile", 0);
  v4 = *((_DWORD *)this
       + (a2 - *((_DWORD *)this + 2467)) / *((_DWORD *)this + 2472)
       + *((_DWORD *)this + 2469) * ((a3 - *((_DWORD *)this + 2468)) / *((_DWORD *)this + 2472))
       + 721);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return (struct CBoardTile *)v4;
}
