//----- (01006AD2) --------------------------------------------------------
void __thiscall CInk::SetInkRedrawFlag(CInk *self)
{
  _BYTE v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CInk::SetInkRedrawFlag", 0);
  *((_DWORD *)self + 3) = 1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
