#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall __noreturn DisplayBoardLoadMsg()
{
  int*v0; // [esp+0h] [ebp-2A8h]
  int*v1; // [esp+0h] [ebp-2A8h]
  uint8_t v2[8]; // [esp+10h] [ebp-298h] BYREF
  WCHAR Text[256]; // [esp+18h] [ebp-290h] BYREF
  WCHAR Caption[70]; // [esp+218h] [ebp-90h] BYREF
  int v5; // [esp+2A4h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "DisplayBoardLoadMsg", 0);
  v5 = 0;
  Helpers::LoadStringW(0, (HINSTANCE)0x3AA3, Caption, (uint16_t *)0x40, 0, v0);
  Helpers::LoadStringW(0, (HINSTANCE)0x3AA4, Text, (uint16_t *)0x100, 0, v1);
  MessageBoxW(0, Text, Caption, 0x30u);
  _exit(0);
}
