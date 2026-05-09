#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall CBoardTileChevron::CareAboutCollisions(int a1, int a2)
{
  uint8_t v3[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardTileChevron::CareAboutCollisions", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return 1;
}
