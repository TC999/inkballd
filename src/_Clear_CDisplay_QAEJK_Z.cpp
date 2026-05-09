#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CDisplay::Clear(CDisplay *this, uint32_t a2)
{
  bool v3; // zf
  int v4; // eax
  int v5; // esi
  int v7; // eax
  uint32_t v8[25]; // [esp+10h] [ebp-7Ch] BYREF
  uint8_t v9[8]; // [esp+74h] [ebp-18h] BYREF
  int v10[3]; // [esp+7Ch] [ebp-10h] BYREF
  int v11; // [esp+88h] [ebp-4h]

  v10[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CDisplay::Clear", v10);
  v3 = *((uint32_t *)this + 6) == 0;
  v11 = 0;
  if ( v3 )
  {
    v4 = -2147467261;
  }
  else
  {
    memset(v8, 0, sizeof(v8));
    v8[20] = a2;
    v7 = *((uint32_t *)this + 3);
    v8[0] = 100;
    v4 = (*(int (__stdcall **)(int, uint32_t, uint32_t, uint32_t, int, uint32_t *))(*(uint32_t *)v7 + 20))(v7, 0, 0, 0, 1024, v8);
  }
  v11 = -1;
  v5 = v4;
  v10[0] = v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return v5;
}
