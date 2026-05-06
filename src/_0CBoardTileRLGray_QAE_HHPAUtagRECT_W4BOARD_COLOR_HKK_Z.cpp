CBoardTile *__thiscall CBoardTileRLGray::CBoardTileRLGray(
        CBoardTile *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  _BYTE v10[16]; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  CBoardTile::CBoardTile(this);
  *(_DWORD *)this = &CBoardTileRLGray::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBoardTileRLGray::CBoardTileRLGray", 0);
  *((_DWORD *)this + 19) = a2;
  *((_DWORD *)this + 20) = a3;
  *((_DWORD *)this + 8) = a4;
  *((_DWORD *)this + 11) = a5;
  *((_DWORD *)this + 25) = a7;
  *((_DWORD *)this + 26) = a8;
  *((_DWORD *)this + 18) = a6;
  v11 = 0;
  *((_DWORD *)this + 17) = 7;
  *((_DWORD *)this + 24) = a6 != 0 ? 2 : 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  AddGameObjectToUpdateList(this);
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return this;
}
