#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall BoardIsActive()
{
  int v0; // esi
  uint8_t v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "BoardIsActive", 0);
  v0 = *((uint32_t *)g_pCGameManager + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return v0;
}
