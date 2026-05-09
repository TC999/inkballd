#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CBoardTile*__thiscall CGameBoard::GetTileByIndices(CGameBoard *this, int a2, int a3)
{
  int v4; // esi
  uint8_t v6[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::GetTileByIndices", 0);
  v4 = *((uint32_t *)this + a2 + a3 * *((uint32_t *)this + 2469) + 721);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return (CBoardTile*)v4;
}
