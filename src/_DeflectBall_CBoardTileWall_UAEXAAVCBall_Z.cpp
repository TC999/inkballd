#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CBoardTileWall::DeflectBall(CBoardTileWall *this, CBall*a2)
{
  int v3; // eax
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardTileWall::DeflectBall", 0);
  v3 = *((uint32_t *)this + 11);
  v5 = 0;
  if ( v3 )
    SetBallColor(a2, v3);
  PerformStandardWallDeflection(this, a2);
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
