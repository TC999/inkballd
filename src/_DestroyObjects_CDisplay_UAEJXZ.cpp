#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CDisplay::DestroyObjects(CDisplay *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // esi
  char v11[8]; // [esp+10h] [ebp-18h] BYREF
  char v12[4]; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  *(uint32_t *)v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::DestroyObjects", (int*)v12);
  v2 = *((uint32_t *)this + 6);
  v13 = 0;
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(uint32_t *)v2 + 8))(v2);
    *((uint32_t *)this + 6) = 0;
  }
  v3 = *((uint32_t *)this + 5);
  if ( v3 )
  {
    (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v3 + 8))(*((uint32_t *)this + 5));
    *((uint32_t *)this + 5) = 0;
  }
  v4 = *((uint32_t *)this + 4);
  if ( v4 )
  {
    (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v4 + 8))(*((uint32_t *)this + 4));
    *((uint32_t *)this + 4) = 0;
  }
  v5 = *((uint32_t *)this + 3);
  if ( v5 )
  {
    (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v5 + 8))(*((uint32_t *)this + 3));
    *((uint32_t *)this + 3) = 0;
  }
  v6 = *((uint32_t *)this + 2);
  if ( v6 )
  {
    (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v6 + 8))(*((uint32_t *)this + 2));
    *((uint32_t *)this + 2) = 0;
  }
  v7 = *((uint32_t *)this + 1);
  if ( v7 )
  {
    *(uint32_t *)v12 = (*(int (__stdcall **)(int, uint32_t, int))(*(uint32_t *)v7 + 80))(v7, *((uint32_t *)this + 7), 8);
    if ( *(int*)v12 < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0xAu, &stru_1002FB8, v12[0]);
    v8 = *((uint32_t *)this + 1);
    if ( v8 )
    {
      (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v8 + 8))(*((uint32_t *)this + 1));
      *((uint32_t *)this + 1) = 0;
    }
  }
  v9 = *(uint32_t *)v12;
  v13 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return v9;
}
