CBoardTile *__thiscall CBoardTileRLColored::CBoardTileRLColored(
        CBoardTile *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6)
{
  _BYTE v8[16]; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+20h] [ebp-4h]

  CBoardTile::CBoardTile(this);
  *(_DWORD *)this = &CBoardTileRLColored::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBoardTileRLColored::CBoardTileRLColored", 0);
  v9 = 0;
  *((_DWORD *)this + 19) = a2;
  *((_DWORD *)this + 20) = a3;
  *((_DWORD *)this + 8) = a4;
  *((_DWORD *)this + 11) = a5;
  *((_DWORD *)this + 18) = a6;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 17) = 7;
  *((_DWORD *)this + 23) = a6 != 0 ? 2 : 0;
  AddGameObjectToUpdateList(this);
  AddRLColoredWallToList(this);
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return this;
}
