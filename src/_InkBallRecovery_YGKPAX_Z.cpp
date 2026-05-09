#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
DWORD __stdcall InkBallRecovery(PVOID pvParameter)
{
  uint8_t v2[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "InkBallRecovery", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return 0;
}
