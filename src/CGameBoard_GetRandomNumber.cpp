//----- (01008783) --------------------------------------------------------
int __thiscall CGameBoard::GetRandomNumber(CGameBoard *self, int a2)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::GetRandomNumber", 0);
  v2 = _rand() % a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
