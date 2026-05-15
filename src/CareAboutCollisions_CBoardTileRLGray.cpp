#include "global_types.h"
#include <cstdint>

static int CBoardTileRLGray_CareAboutCollisions(int* self, int a2, int a3)
{
  int v4;
  uint8_t v6[16];
  int v7;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v6), "CBoardTileRLGray::CareAboutCollisions", 0);
  if ( self[18] <= 0 )
    v4 = 0;
  else
    v4 = 2;
  v7 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v6)->~CLogBlock();
  return v4;
}
