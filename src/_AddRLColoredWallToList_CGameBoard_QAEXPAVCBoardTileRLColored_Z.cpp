#include "global_types.h"
#include <cstdint>

static void CGameBoard_AddRLColoredWallToList(CGameBoard* self, CBoardTileRLColored* a2)
{
  int v3;
  uint8_t v4[8];

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CGameBoard::AddRLColoredWallToList", 0);
  v3 = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 366 * sizeof(uint32_t));
  if ( v3 < 289 )
  {
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + (v3 + 367) * sizeof(uint32_t)) = reinterpret_cast<uint32_t>(a2);
    ++*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 366 * sizeof(uint32_t));
  }
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
