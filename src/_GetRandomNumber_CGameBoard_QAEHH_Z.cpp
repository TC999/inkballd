#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "global_types.h"

int CGameBoard::GetRandomNumber(CGameBoard *self, int a2)
{
  int v2;
  uint8_t v4[8];

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::GetRandomNumber", 0);
  v2 = rand() % a2;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}
