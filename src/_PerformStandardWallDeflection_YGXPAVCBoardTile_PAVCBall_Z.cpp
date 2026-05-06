void __stdcall PerformStandardWallDeflection(struct CBoardTile *a1, struct CBall *a2)
{
  _BYTE v2[16]; // [esp+10h] [ebp-14h] BYREF
  int v3; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "PerformStandardWallDeflection", 0);
  v3 = 0;
  CBall::Collide(a2, PointIntersectsWithTileDeflect);
  v3 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
