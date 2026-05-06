BOOL __stdcall CBoardTile::CareAboutCollisions(int a1, int a2)
{
  BOOL v2; // esi
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardTile::CareAboutCollisions", 0);
  v2 = *(_DWORD *)(a1 + 140) != 0;
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
