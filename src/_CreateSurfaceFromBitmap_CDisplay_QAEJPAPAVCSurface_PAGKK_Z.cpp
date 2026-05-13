#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
uint32_t CreateSurfaceFromBitmap_CDisplay(CDisplay* self, CSurface**a2, HINSTANCE name, uint32_t a4, int cy)
{
    uint32_t v14;
  uint32_t v6; // esi
  HMODULE ModuleHandleW; // eax
  CSurface *v8; // ecx
  CSurface*v9; // eax
  int*v11; // [esp+0h] [ebp-C8h]
  int*v12; // [esp+0h] [ebp-C8h]
  int*v13; // [esp+0h] [ebp-C8h]
  _DDSURFACEDESC2 v14; // [esp+10h] [ebp-B8h] BYREF
  uint8_t pv[4]; // [esp+8Ch] [ebp-3Ch] BYREF
  DWORD v16; // [esp+90h] [ebp-38h]
  DWORD v17; // [esp+94h] [ebp-34h]
  uint8_t v18[8]; // [esp+A4h] [ebp-24h] BYREF
  CDisplay *v19; // [esp+ACh] [ebp-1Ch]
  HGDIOBJ ho; // [esp+B0h] [ebp-18h]
  uint32_t v21[4]; // [esp+B4h] [ebp-14h] BYREF
  int v22; // [esp+C4h] [ebp-4h]

  v19 = self;
  v21[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CDisplay::CreateSurfaceFromBitmap", (int*)v21);
  v22 = 0;
  if ( name && a2 )
  {
    uint32_t v14; // auto-declared
    if ( *((uint32_t *)self + 1) )
    {
      *a2 = 0;
      ModuleHandleW = GetModuleHandleW(0);
      ho = Helpers::LoadImageW(ModuleHandleW, name, 0, a4, cy, 0x2000u, 0, v11);
      if ( ho
        || (ho = Helpers::LoadImageW(0, name, 0, a4, cy, 0x2010u, (uint32_t)v21, v12), (v21[0] & 0x80000000) == 0) )
      {
        Helpers::GetObjectW(ho, (void*)0x18, pv, 0, v12);
        memset(&v14, 0, sizeof(v14));
        v14.dwWidth = v16;
        v14.dwSize = 124;
        v14.dwFlags = 7;
        v14.ddsCaps.dwCaps = 64;
        v14.dwHeight = v17;
        LOBYTE(v22) = 1;
        v8 = (CSurface *)operator new(0x84u);
        LOBYTE(v22) = 2;
        if ( v8 )
          v9 = new (v8) CSurface();
        else
          v9 = 0;
        *a2 = v9;
        v22 = 0;
        if ( (v21[0] & 0x80000000) != 0
          || (v21[0] = CSurface::Create((LPDIRECTDRAWSURFACE7 *)*a2, *((struct IDirectDraw7 **)v19 + 1), &v14),
              (v21[0] & 0x80000000) != 0)
          || (v21[0] = CSurface::DrawBitmap(*a2, (HDC)ho, 0, 0, 0, 0), (v21[0] & 0x80000000) != 0) )
        {
          if ( *a2 )
          {
              delete *a2;
            *a2 = 0;
          }
        }
        Helpers::DeleteObject(ho, 0, v13);
      }
      v6 = v21[0];
    }
    else
    {
      v21[0] = -2147418113;
      v6 = -2147418113;
    }
  }
  else
  {
    v6 = -2147024809;
    v21[0] = -2147024809;
  }
  v22 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v18)->~CLogBlock();
  return v6;
}
