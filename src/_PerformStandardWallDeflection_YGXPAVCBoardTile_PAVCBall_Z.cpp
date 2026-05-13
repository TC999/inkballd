#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void __stdcall PerformStandardWallDeflection(CBoardTile*a1, CBall*a2)
{
  uint8_t v2[16]; // [esp+10h] [ebp-14h] BYREF
  int v3; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v2), "PerformStandardWallDeflection", 0);
  v3 = 0;
  CBall::Collide(a2, PointIntersectsWithTileDeflect);
  v3 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}
