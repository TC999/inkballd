CBoardTile *__thiscall CBoardTileChevron::CBoardTileChevron(CBoardTile *this, int a2, int a3, int a4, int a5)
{
  _BYTE v7[8]; // [esp+4h] [ebp-8h] BYREF

  CBoardTile::CBoardTile(this);
  *(_DWORD *)this = &CBoardTileChevron::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBoardTileChevron::CBoardTileChevron", 0);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 19) = a2;
  *((_DWORD *)this + 20) = a3;
  *((_DWORD *)this + 22) = a5;
  *((_DWORD *)this + 8) = a4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return this;
}
