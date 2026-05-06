void __thiscall CInk::SetInkModifiedFlag(CInk *this)
{
  _BYTE v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CInk::SetInkModifiedFlag", 0);
  *((_DWORD *)this + 2) = 1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
