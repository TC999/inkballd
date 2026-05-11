#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
HWND __stdcall GetMainWindowHwnd()
{
  int v0; // esi
  uint8_t v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "GetMainWindowHwnd", 0);
  v0 = *((uint32_t *)g_pCGameBoard + 2480);
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
  return (HWND)v0;
}

#endif
