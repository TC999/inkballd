#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
extern "C" DWORD __stdcall InkBallRecovery(PVOID pvParameter)
{
  uint8_t v2[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "InkBallRecovery", 0);
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
  return 0;
}
