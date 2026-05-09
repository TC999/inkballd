#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CDisplay::BltInk(CDisplay *this, struct tagRECT *a2)
{
  int v3; // ecx
  int v4; // esi
  uint8_t v6[8]; // [esp+10h] [ebp-18h] BYREF
  int v7[3]; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  v7[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CDisplay::BltInk", v7);
  v8 = 0;
  if ( *((uint32_t *)this + 3) && (v3 = *((uint32_t *)this + 5)) != 0 )
  {
    v7[0] = (*(int (__stdcall **)(uint32_t, struct tagRECT *, int, struct tagRECT *, int, uint32_t))(**((uint32_t **)this + 3)
                                                                                               + 20))(
              *((uint32_t *)this + 3),
              a2,
              v3,
              a2,
              0x1000000,
              0);
    v4 = v7[0];
  }
  else
  {
    v4 = -2147467261;
    v7[0] = -2147467261;
  }
  v8 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return v4;
}
