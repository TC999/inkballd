#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall CSink::CursorMove(CSink *this, uint32_t a2, uint32_t a3, HWND a4, int a5, int a6)
{
  int v6; // esi
  uint8_t v8[8]; // [esp+4h] [ebp-Ch] BYREF
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CSink::CursorMove", &v9);
  v6 = v9;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v6;
}
