//----- (010081CF) --------------------------------------------------------
void __thiscall CGameBoard::AddBallToUpdateList(CGameBoard *self, struct CBall *a2)
{
  int v3; // ecx
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddBallToUpdateList", 0);
  v3 = *((_DWORD *)self + 301);
  if ( v3 < 64 )
  {
    *((_DWORD *)self + v3 + 302) = a2;
    ++*((_DWORD *)self + 301);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
