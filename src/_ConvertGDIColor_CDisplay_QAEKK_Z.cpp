#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

int CDisplay::ConvertGDIColor(COLORREF color)
{
  int v3; // edi
  bool v4; // zf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  uint32_t v9[21]; // [esp+10h] [ebp-9Ch] BYREF
  uint32_t v10; // [esp+64h] [ebp-48h]
  uint8_t v11[8]; // [esp+8Ch] [ebp-20h] BYREF
  COLORREF Pixel; // [esp+94h] [ebp-18h]
  int v13; // [esp+98h] [ebp-14h]
  HDC hdc[3]; // [esp+9Ch] [ebp-10h] BYREF
  int v15; // [esp+A8h] [ebp-4h]

  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::ConvertGDIColor", 0);
  v4 = *((uint32_t *)this + 5) == 0;
  v15 = 0;
  if ( !v4 )
  {
    v13 = -1;
    if ( color != -1 )
    {
      v6 = (*(int (__stdcall **)(uint32_t, HDC *))(**((uint32_t **)this + 5) + 68))(*((uint32_t *)this + 5), hdc);
      if ( v6 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x22u, &stru_1002FB8, v6);
      }
      else
      {
        Pixel = GetPixel(hdc[0], 0, 0);
        SetPixel(hdc[0], 0, 0, color);
        (*(void (__stdcall **)(uint32_t, HDC))(**((uint32_t **)this + 5) + 104))(*((uint32_t *)this + 5), hdc[0]);
      }
    }
    v7 = *((uint32_t *)this + 5);
    v9[0] = 124;
    if ( !(*(int (__stdcall **)(int, uint32_t, uint32_t *, int, uint32_t))(*(uint32_t *)v7 + 100))(v7, 0, v9, 1, 0) )
    {
      v13 = *(uint32_t *)v9[9];
      if ( v10 < 0x20 )
        v13 &= (1 << v10) - 1;
      (*(void (__stdcall **)(uint32_t, uint32_t))(**((uint32_t **)this + 5) + 128))(*((uint32_t *)this + 5), 0);
    }
    if ( color != -1 )
    {
      v8 = (*(int (__stdcall **)(uint32_t, HDC *))(**((uint32_t **)this + 5) + 68))(*((uint32_t *)this + 5), hdc);
      if ( v8 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x23u, &stru_1002FB8, v8);
      }
      else
      {
        SetPixel(hdc[0], 0, 0, Pixel);
        (*(void (__stdcall **)(uint32_t, HDC))(**((uint32_t **)this + 5) + 104))(*((uint32_t *)this + 5), hdc[0]);
      }
    }
    v3 = v13;
  }
  v15 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v11)->~CLogBlock();
  return v3;
}
