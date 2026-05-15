#include "global_types.h"
#include <cstdint>

static BOOL CBoardTile_CareAboutCollisions(int a1, int a2)
{
  BOOL v2;
  uint8_t v4[16];
  int v5;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CBoardTile::CareAboutCollisions", 0);
  v2 = *reinterpret_cast<uint32_t*>(static_cast<uintptr_t>(a1) + 140) != 0;
  v5 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}
