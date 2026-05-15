//----- (0100856C) --------------------------------------------------------
void __thiscall CGameBoard::AddBall(CGameBoard *this, struct CBall *a2)
{
  _DWORD *v3; // eax
  int v4; // edx
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::AddBall", 0);
  v3 = (_DWORD *)((char *)this + 2624);
  v4 = *((_DWORD *)this + 656);
  if ( v4 < 64 )
  {
    *((_DWORD *)a2 + 41) = v4;
    *((_DWORD *)this + (*v3)++ + 657) = a2;
    ++*((_DWORD *)this + 2473);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
