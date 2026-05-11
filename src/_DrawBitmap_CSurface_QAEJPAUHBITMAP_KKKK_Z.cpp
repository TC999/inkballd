#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CSurface::DrawBitmap(CSurface *this, HDC h, uint32_t xSrc, uint32_t ySrc, int wSrc, int hSrc)
{
  int v7; // eax
  int v8; // eax
  int v9; // esi
  HDC CompatibleDC; // eax
  int v11; // ebx
  signed int LastError; // eax
  int*v14; // [esp+0h] [ebp-C4h]
  int*v15; // [esp+0h] [ebp-C4h]
  int*v16; // [esp+0h] [ebp-C4h]
  int*v17; // [esp+0h] [ebp-C4h]
  uint32_t v18[31]; // [esp+10h] [ebp-B4h] BYREF
  uint8_t pv[4]; // [esp+8Ch] [ebp-38h] BYREF
  uint32_t v20; // [esp+90h] [ebp-34h]
  int v21; // [esp+94h] [ebp-30h]
  uint8_t v22[8]; // [esp+A4h] [ebp-20h] BYREF
  HDC hdcDest; // [esp+ACh] [ebp-18h] BYREF
  HDC hdcSrc; // [esp+B0h] [ebp-14h]
  char v25[4]; // [esp+B4h] [ebp-10h] BYREF
  int v26; // [esp+C0h] [ebp-4h]

  *(uint32_t *)v25 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v22, "CSurface::DrawBitmap", (int*)v25);
  v26 = 0;
  if ( !h || !*(uint32_t *)this )
  {
    v9 = -2147024809;
    *(uint32_t *)v25 = -2147024809;
    goto LABEL_26;
  }
  v7 = (*(int (__stdcall **)(uint32_t))(**(uint32_t **)this + 108))(*(uint32_t *)this);
  *(uint32_t *)v25 = v7;
  if ( v7 < 0 )
    goto LABEL_6;
  v8 = *(uint32_t *)this;
  v18[0] = 124;
  (*(void (__stdcall **)(int, uint32_t *))(*(uint32_t *)v8 + 88))(v8, v18);
  if ( v18[19] == 4 )
  {
    v7 = -2147467263;
    *(uint32_t *)v25 = -2147467263;
LABEL_6:
    v9 = v7;
    goto LABEL_26;
  }
  CompatibleDC = Helpers::CreateCompatibleDC(0, 0, v14);
  hdcSrc = CompatibleDC;
  if ( CompatibleDC )
  {
    Helpers::SelectObject(CompatibleDC, h, 0, v15);
    Helpers::GetObjectW(h, (void*)0x18, pv, 0, v16);
    if ( !wSrc )
      wSrc = v20;
    v11 = hSrc;
    if ( !hSrc )
      v11 = v21;
    *(uint32_t *)v25 = (*(int (__stdcall **)(uint32_t, HDC *))(**(uint32_t **)this + 68))(*(uint32_t *)this, &hdcDest);
    if ( *(int*)v25 < 0 )
    {
      if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x27u, &stru_1002FB8, v25[0]);
    }
    else
    {
      StretchBlt(hdcDest, 0, 0, v18[3], v18[2], hdcSrc, xSrc, ySrc, wSrc, v11, 0xCC0020u);
      *(uint32_t *)v25 = (*(int (__stdcall **)(uint32_t, HDC))(**(uint32_t **)this + 104))(*(uint32_t *)this, hdcDest);
      if ( *(int*)v25 < 0
        && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
        && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x26u, &stru_1002FB8, v25[0]);
      }
    }
    Helpers::DeleteDC(hdcSrc, 0, v17);
  }
  else
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v25 = LastError;
  }
  v9 = *(uint32_t *)v25;
LABEL_26:
  v26 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v22)->~CLogBlock();
  return v9;
}

#endif
