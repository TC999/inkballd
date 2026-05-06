CBoardObject *__thiscall CBoardTile::CBoardTile(CBoardObject *this, int a2, int a3, int a4, int a5)
{
  _BYTE v7[8]; // [esp+4h] [ebp-8h] BYREF

  CBoardObject::CBoardObject(this);
  *(_DWORD *)this = &CBoardTile::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBoardTile::CBoardTile", 0);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = a2;
  *((_DWORD *)this + 19) = a3;
  *((_DWORD *)this + 20) = a4;
  *((_DWORD *)this + 8) = a5;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return this;
}
