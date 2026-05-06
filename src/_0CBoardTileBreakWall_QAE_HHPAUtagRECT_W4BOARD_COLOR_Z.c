CBoardTile *__thiscall CBoardTileBreakWall::CBoardTileBreakWall(CBoardTile *this, int a2, int a3, int a4, int a5)
{
  _BYTE v7[8]; // [esp+4h] [ebp-8h] BYREF

  CBoardTile::CBoardTile(this);
  *(_DWORD *)this = &CBoardTileBreakWall::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBoardTileBreakWall::CBoardTileBreakWall", 0);
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 19) = a2;
  *((_DWORD *)this + 20) = a3;
  *((_DWORD *)this + 8) = a4;
  *((_DWORD *)this + 17) = 9;
  *((_DWORD *)this + 18) = 4;
  *((_DWORD *)this + 11) = a5;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return this;
}
