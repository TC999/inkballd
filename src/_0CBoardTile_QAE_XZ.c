CBoardTile *__thiscall CBoardTile::CBoardTile(CBoardTile *this)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  CBoardObject::CBoardObject(this);
  *(_DWORD *)this = &CBoardTile::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardTile::CBoardTile", 0);
  *((_DWORD *)this + 18) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
