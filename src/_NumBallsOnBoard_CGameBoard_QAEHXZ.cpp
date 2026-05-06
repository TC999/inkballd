int __thiscall CGameBoard::NumBallsOnBoard(CGameBoard *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::NumBallsOnBoard", 0);
  v2 = *((_DWORD *)this + 656);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
