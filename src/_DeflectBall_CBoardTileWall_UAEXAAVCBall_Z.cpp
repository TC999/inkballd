#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern "C" void SetBallColor(void* ball, uint32_t color);
extern "C" void PerformStandardWallDeflection(void* tile, void* ball);
void DeflectBall_CBoardTileWall(CBoardTileWall* self, CBall* a2)
{
  int v3; // eax
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CBoardTileWall::DeflectBall", 0);
  v3 = *((uint32_t *)self + 11);
  v5 = 0;
  if ( v3 )
    SetBallColor(a2, v3);
  PerformStandardWallDeflection(self, a2);
  v5 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
