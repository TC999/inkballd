#include "global_types.h"
#include <cstdint>
#include <windows.h>
int CGameBoard::BltBoardToInk(CGameBoard* self, struct tagRECT *a2, int a3)
{
  int v3;
  uint8_t v5[8];
  int v6[3];
  int v7;

  v6[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "CGameBoard::BltBoardToInk", 0);
  v7 = 0;
  CDisplay::ClearInk(g_pDisplay, a2, a3);
  v3 = v6[0];
  v7 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return v3;
}