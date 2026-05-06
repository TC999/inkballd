void __thiscall CInk::~CInk(CInk *this)
{
  _BYTE v2[16]; // [esp+10h] [ebp-14h] BYREF
  int v3; // [esp+20h] [ebp-4h]

  *(_DWORD *)this = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CInk::~CInk", 0);
  v3 = 0;
  CInk::Cleanup(this);
  v3 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
