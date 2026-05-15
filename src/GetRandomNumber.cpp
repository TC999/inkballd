#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "global_types.h"

extern CGameBoard* g_pCGameBoard;

int __stdcall GetRandomNumber(int a1)
{
  int RandomNumber;
  int v2;
  uint8_t v4[16];
  int v5;

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "GetRandomNumber", 0);
  v5 = 0;
  RandomNumber = CGameBoard::GetRandomNumber(g_pCGameBoard, a1);
  v5 = -1;
  v2 = RandomNumber;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}
