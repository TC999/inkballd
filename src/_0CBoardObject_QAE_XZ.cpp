CBoardObject *__thiscall CBoardObject::CBoardObject(CBoardObject *this)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  *(_DWORD *)this = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardObject::CBoardObject", 0);
  *((_DWORD *)this + 8) = 0;
  *((double *)this + 1) = 0.0;
  *((_DWORD *)this + 10) = 0;
  *((double *)this + 2) = 0.0;
  *((_DWORD *)this + 11) = 0;
  *((double *)this + 6) = 1.0;
  *((double *)this + 7) = 1.0;
  *((_DWORD *)this + 6) = 32;
  *((_DWORD *)this + 7) = 32;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
