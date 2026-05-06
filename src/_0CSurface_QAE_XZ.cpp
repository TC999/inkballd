CSurface *__thiscall CSurface::CSurface(CSurface *this)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CSurface::CSurface", 0);
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 32) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
