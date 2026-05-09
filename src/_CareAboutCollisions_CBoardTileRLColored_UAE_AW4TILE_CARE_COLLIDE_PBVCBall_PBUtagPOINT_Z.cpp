#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CBoardTileRLColored::CareAboutCollisions(int*this, int a2, int a3)
{
  int v4; // esi
  uint8_t v6[16]; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBoardTileRLColored::CareAboutCollisions", 0);
  if ( this[18] <= 0 )
    v4 = 0;
  else
    v4 = 2;
  v7 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return v4;
}
