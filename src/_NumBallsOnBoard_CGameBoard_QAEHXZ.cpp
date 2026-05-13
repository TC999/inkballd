#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int NumBallsOnBoard_CGameBoard(CGameBoard *self)
{
  int v2; // esi
  uint8_t v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CGameBoard::NumBallsOnBoard", 0);
  v2 = *((uint32_t *)self + 656);
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}
