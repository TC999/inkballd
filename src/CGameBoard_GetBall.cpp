//----- (010085EF) --------------------------------------------------------
struct CBall *__thiscall CGameBoard::GetBall(CGameBoard *this, int a2)
{
  int v3; // esi
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::GetBall", 0);
  v3 = *((_DWORD *)this + a2 + 657);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return (struct CBall *)v3;
}
