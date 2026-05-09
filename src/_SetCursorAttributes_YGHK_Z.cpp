#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall SetCursorAttributes(uint32_t a1)
{
  int v1; // esi
  int v2; // ecx
  uint8_t v4[8]; // [esp+10h] [ebp-28h] BYREF
  int v5; // [esp+18h] [ebp-20h] BYREF
  int v6; // [esp+1Ch] [ebp-1Ch] BYREF
  float v7; // [esp+20h] [ebp-18h] BYREF
  int v8; // [esp+24h] [ebp-14h] BYREF
  int v9[3]; // [esp+28h] [ebp-10h] BYREF
  int v10; // [esp+34h] [ebp-4h]

  v1 = 0;
  v9[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "SetCursorAttributes", v9);
  v8 = 0;
  v2 = *(uint32_t *)g_pIInkObject;
  v10 = 0;
  v9[0] = (*(int (__stdcall **)(struct IInkObject *, uint32_t, int*))(v2 + 44))(g_pIInkObject, a1, &v8);
  if ( v9[0] >= 0 )
  {
    v7 = 100.0;
    v9[0] = (*(int (__stdcall **)(int, uint32_t, int, float *))(*(uint32_t *)v8 + 12))(
              v8,
              *(uint32_t *)GUID_PEN_STYLE.Data4,
              4,
              &v7);
    v6 = 20;
    v9[0] = (*(int (__stdcall **)(int, uint32_t, int, int*))(*(uint32_t *)v8 + 12))(
              v8,
              GUID_DRAWING_FLAGS.Data1,
              4,
              &v6);
    v5 = 0;
    v9[0] = (*(int (__stdcall **)(int, uint32_t, int, int*))(*(uint32_t *)v8 + 12))(
              v8,
              *(uint32_t *)&GUID_PEN_STYLE.Data2,
              4,
              &v5);
    v9[0] = (*(int (__stdcall **)(struct IInkObject *, uint32_t, int))(*(uint32_t *)g_pIInkObject + 40))(
              g_pIInkObject,
              a1,
              v8);
    (*(void (__stdcall **)(int))(*(uint32_t *)v8 + 8))(v8);
  }
  else
  {
    v1 = -1;
  }
  v10 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v1;
}
