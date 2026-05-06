void __thiscall CBoardTileRLColored::DeflectBall(CBoardTileRLColored *this, struct CBall *a2)
{
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardTileRLColored::DeflectBall", 0);
  v4 = 0;
  PerformStandardWallDeflection(this, a2);
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
