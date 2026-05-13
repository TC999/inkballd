#include "global_types.h"
#include <cstdint>

extern void CGameBoard_AddRLColoredWallToList(CGameBoard* self, CBoardTileRLColored* a2);

void __stdcall AddRLColoredWallToList(CBoardTileRLColored* a1)
{
  uint8_t v1[16];
  int v2;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v1), "AddRLColoredWallToList", 0);
  v2 = 0;
  CGameBoard_AddRLColoredWallToList(g_pCGameBoard, a1);
  v2 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}
