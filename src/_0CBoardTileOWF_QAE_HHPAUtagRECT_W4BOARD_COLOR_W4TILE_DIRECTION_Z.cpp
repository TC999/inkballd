CBoardTile *__thiscall CBoardTileOWF::CBoardTileOWF(CBoardTile *this, int a2, int a3, int a4, int a5, int a6)
{
  _BYTE v8[8]; // [esp+4h] [ebp-8h] BYREF

  CBoardTile::CBoardTile(this);
  *(_DWORD *)this = &CBoardTileOWF::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBoardTileOWF::CBoardTileOWF", 0);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 19) = a2;
  *((_DWORD *)this + 20) = a3;
  *((_DWORD *)this + 8) = a4;
  *((_DWORD *)this + 11) = a5;
  *((_DWORD *)this + 17) = 10;
  *((_DWORD *)this + 22) = a6;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return this;
}
