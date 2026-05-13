#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void __stdcall SetCursorAttributes(uint32_t a1)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  float v5; // [esp+14h] [ebp-20h]
  uint8_t v6[16]; // [esp+1Ch] [ebp-18h] BYREF
  int v7; // [esp+2Ch] [ebp-8h]
  int v8; // [esp+30h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v6), "SetCursorAttributes", 0);
  v2 = 0;
  v8 = 0;
  if ( a1 == 1 )
  {
    v3 = (*(int (__stdcall **)(void*, uint32_t))(**((uint32_t **)g_pIInkObject) + 32))((void*)*((uint32_t *)g_pIInkObject), 0);
    if ( v3 >= 0 )
    {
      v5 = 6.0f;
      ((int (__stdcall *)(int, uint32_t, int, float*))((*((uint32_t **)v3)))[3])(v3, 19, 2, &v5);
      v2 = 1;
    }
  }
  if ( a1 >= 2 )
  {
    v4 = (*(int (__stdcall **)(void*, uint32_t))(**((uint32_t **)g_pIInkObject) + 32))((void*)*((uint32_t *)g_pIInkObject), 0);
    if ( v4 >= 0 )
    {
      ((int (__stdcall *)(int, uint32_t, int, int*))((*((uint32_t **)v4)))[3])(v4, 21, 0, &v7);
      v2 = 1;
    }
  }
  if ( v2 )
  {
    (*(int (__stdcall **)(void*, uint32_t))(**((uint32_t **)g_pIInkObject) + 36))((void*)*((uint32_t *)g_pIInkObject), 0);
    (*(int (__stdcall **)(void*, uint32_t))(**((uint32_t **)g_pIInkObject) + 20))((void*)*((uint32_t *)g_pIInkObject), 2);
  }
  v8 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v6)->~CLogBlock();
}
