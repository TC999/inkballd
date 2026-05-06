CMovingObject *__thiscall CMovingObject::CMovingObject(CMovingObject *this)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  CBoardObject::CBoardObject(this);
  *(_DWORD *)this = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CMovingObject::CMovingObject", 0);
  *((double *)this + 8) = 0.0;
  *((double *)this + 9) = 0.0;
  *((double *)this + 10) = 0.0;
  *((double *)this + 11) = 0.0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
