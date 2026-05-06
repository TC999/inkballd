int __thiscall CGameBoard::Init(CGameBoard *this)
{
  CInk *v2; // ecx
  int v3; // eax
  int v4; // esi
  _BYTE v6[8]; // [esp+10h] [ebp-18h] BYREF
  int v7[3]; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  v7[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::Init", v7);
  v2 = (CInk *)*((_DWORD *)this + 2481);
  v8 = 0;
  v3 = CInk::Init(v2);
  v8 = -1;
  v7[0] = v3;
  v4 = v3;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return v4;
}
