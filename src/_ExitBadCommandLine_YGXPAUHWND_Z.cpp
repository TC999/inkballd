#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void __stdcall ExitBadCommandLine(HWND hWnd)
{
  uint8_t v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v1), "ExitBadCommandLine", 0);
  v2 = 0;
  DispError(hWnd, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AA7);
  _exit(0);
}
