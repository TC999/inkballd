#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int ConvertGDIColor_CSurface(CSurface* self, COLORREF color)
{
  int v3; // edi
  int v4; // eax
  bool v5; // zf
  int v7; // eax
  int v8; // eax
  int v9; // eax
  uint32_t v10[21]; // [esp+10h] [ebp-9Ch] BYREF
  uint32_t v11; // [esp+64h] [ebp-48h]
  uint8_t v12[8]; // [esp+8Ch] [ebp-20h] BYREF
  COLORREF Pixel; // [esp+94h] [ebp-18h]
  int v14; // [esp+98h] [ebp-14h]
  HDC hdc[3]; // [esp+9Ch] [ebp-10h] BYREF
  int v16; // [esp+A8h] [ebp-4h]

  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CSurface::ConvertGDIColor", 0);
  v4 = *(uint32_t *)self;
  v5 = *(uint32_t *)self == 0;
  v16 = 0;
  if ( !v5 )
  {
    v14 = -1;
    if ( color != -1 )
    {
      v7 = (*(int (__stdcall **)(int, HDC *))(*(uint32_t *)v4 + 68))(v4, hdc);
      if ( v7 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x2Bu, &stru_1002FB8, v7);
      }
      else
      {
        Pixel = GetPixel(hdc[0], 0, 0);
        SetPixel(hdc[0], 0, 0, color);
        (*(void (__stdcall **)(uint32_t, HDC))(**(uint32_t **)self + 104))(*(uint32_t *)self, hdc[0]);
      }
    }
    v8 = *(uint32_t *)self;
    v10[0] = 124;
    if ( !(*(int (__stdcall **)(int, uint32_t, uint32_t *, int, uint32_t))(*(uint32_t *)v8 + 100))(v8, 0, v10, 1, 0) )
    {
      v14 = *(uint32_t *)v10[9];
      if ( v11 < 0x20 )
        v14 &= (1 << v11) - 1;
      (*(void (__stdcall **)(uint32_t, uint32_t))(**(uint32_t **)self + 128))(*(uint32_t *)self, 0);
    }
    if ( color != -1 )
    {
      v9 = (*(int (__stdcall **)(uint32_t, HDC *))(**(uint32_t **)self + 68))(*(uint32_t *)self, hdc);
      if ( v9 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x2Cu, &stru_1002FB8, v9);
      }
      else
      {
        SetPixel(hdc[0], 0, 0, Pixel);
        (*(void (__stdcall **)(uint32_t, HDC))(**(uint32_t **)self + 104))(*(uint32_t *)self, hdc[0]);
      }
    }
    v3 = v14;
  }
  v16 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v12)->~CLogBlock();
  return v3;
}
