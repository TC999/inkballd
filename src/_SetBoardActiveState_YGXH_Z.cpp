#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <new>
void __stdcall SetBoardActiveState(int a1)
{
  uint8_t v1[8]; // [esp+0h] [ebp-8h] BYREF

  new (v1) Helpers::CLogBlock(v1, "SetBoardActiveState", 0);
  *((uint32_t *)g_pCGameManager + 1) = a1;
  reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}

