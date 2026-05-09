#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CSurface::SetColorKey(CSurface *this, COLORREF a2)
{
  int v3; // eax
  int v4; // esi
  int v6; // eax
  int v7; // esi
  uint8_t v8[8]; // [esp+10h] [ebp-20h] BYREF
  uint32_t v9[2]; // [esp+18h] [ebp-18h] BYREF
  int v10[3]; // [esp+20h] [ebp-10h] BYREF
  int v11; // [esp+2Ch] [ebp-4h]

  v10[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CSurface::SetColorKey", v10);
  v11 = 0;
  if ( *(uint32_t *)this )
  {
    *((uint32_t *)this + 32) = 1;
    v9[0] = CSurface::ConvertGDIColor(this, a2);
    v6 = CSurface::ConvertGDIColor(this, a2);
    v7 = *(uint32_t *)this;
    v9[1] = v6;
    v3 = (*(int (__stdcall **)(int, int, uint32_t *))(*(uint32_t *)v7 + 116))(v7, 8, v9);
  }
  else
  {
    v3 = -2147467261;
  }
  v11 = -1;
  v4 = v3;
  v10[0] = v3;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v4;
}
