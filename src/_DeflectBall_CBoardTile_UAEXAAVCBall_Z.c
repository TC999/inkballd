void __thiscall CBoardTile::DeflectBall(CBoardTile *this, struct CBall *a2)
{
  _BYTE v2[16]; // [esp+10h] [ebp-14h] BYREF
  int v3; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CBoardTile::DeflectBall", 0);
  v3 = 0;
  CBall::SetTallness(a2, 0);
  v3 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
