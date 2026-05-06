void __thiscall CBoardTileBreakWall::DeflectBall(CBoardTileBreakWall *this, struct CBall *a2)
{
  int v3; // eax
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardTileBreakWall::DeflectBall", 0);
  v5 = 0;
  PerformStandardWallDeflection(this, a2);
  v3 = *((_DWORD *)this + 11);
  if ( !v3 || v3 == *((_DWORD *)a2 + 11) )
  {
    ConvertTileToFloor(this);
    ScoreBreak(a2);
  }
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
