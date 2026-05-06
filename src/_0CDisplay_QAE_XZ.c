CDisplay *__thiscall CDisplay::CDisplay(CDisplay *this)
{
  _BYTE v3[8]; // [esp+8h] [ebp-8h] BYREF

  *(_DWORD *)this = &CDisplay::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CDisplay::CDisplay", 0);
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
