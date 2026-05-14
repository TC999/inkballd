#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void __stdcall DispError(HWND hWnd, HINSTANCE uID, HINSTANCE a3)
{
  int *v3 = 0; // [esp+0h] [ebp-20A4h]
  int *v4 = 0; // [esp+0h] [ebp-20A4h]
  uint8_t v5[8]; // [esp+Ch] [ebp-2098h] BYREF
  WCHAR Text[4096]; // [esp+14h] [ebp-2090h] BYREF
  WCHAR Caption[64]; // [esp+2014h] [ebp-90h] BYREF
  int v8; // [esp+20A0h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "DispError", 0);
  v8 = 0;
  Helpers::LoadStringW(0, uID, Caption, (uint16_t *)0x40, 0, v3);
  Helpers::LoadStringW(0, a3, Text, (uint16_t *)0x1000, 0, v4);
  MessageBoxW(hWnd, Text, Caption, 0x10u);
  v8 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
}
