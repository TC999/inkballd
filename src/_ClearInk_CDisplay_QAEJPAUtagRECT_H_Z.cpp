#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CDisplay::ClearInk(CDisplay *this, struct tagRECT *a2, int a3)
{
  int v4; // eax
  int v5; // esi
  uint8_t v7[8]; // [esp+10h] [ebp-18h] BYREF
  int v8[3]; // [esp+18h] [ebp-10h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  v8[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CDisplay::ClearInk", v8);
  v9 = 0;
  if ( *((uint32_t *)this + 5) )
    v4 = (*(int (__stdcall **)(uint32_t, struct tagRECT *, uint32_t, struct tagRECT *, int, uint32_t))(**((uint32_t **)this + 5)
                                                                                               + 20))(
           *((uint32_t *)this + 5),
           a2,
           *((uint32_t *)this + 6),
           a2,
           0x1000000,
           0);
  else
    v4 = -2147467261;
  v9 = -1;
  v5 = v4;
  v8[0] = v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v5;
}
