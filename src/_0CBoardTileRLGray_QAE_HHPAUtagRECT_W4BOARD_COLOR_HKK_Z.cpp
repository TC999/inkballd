#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CBoardTile *__thiscall CBoardTileRLGray::CBoardTileRLGray(
        CBoardTile *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8)
{
  uint8_t v10[16]; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  CBoardTile::CBoardTile(this);
  *(uint32_t *)this = &CBoardTileRLGray::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBoardTileRLGray::CBoardTileRLGray", 0);
  *((uint32_t *)this + 19) = a2;
  *((uint32_t *)this + 20) = a3;
  *((uint32_t *)this + 8) = a4;
  *((uint32_t *)this + 11) = a5;
  *((uint32_t *)this + 25) = a7;
  *((uint32_t *)this + 26) = a8;
  *((uint32_t *)this + 18) = a6;
  v11 = 0;
  *((uint32_t *)this + 17) = 7;
  *((uint32_t *)this + 24) = a6 != 0 ? 2 : 0;
  *((uint32_t *)this + 16) = 0;
  *((uint32_t *)this + 22) = 0;
  *((uint32_t *)this + 23) = 0;
  AddGameObjectToUpdateList(this);
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return this;
}
