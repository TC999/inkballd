#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CDisplay::CreateSurface(CDisplay *this, CSurface**a2, void*a3, DWORD a4)
{
  int v5; // eax
  int v6; // esi
  CSurface *v8; // ecx
  CSurface*v9; // eax
  uint8_t v11[8]; // [esp+8Ch] [ebp-20h] BYREF
  CDisplay *v12; // [esp+94h] [ebp-18h]
  int v13[4]; // [esp+98h] [ebp-14h] BYREF
  int v14; // [esp+A8h] [ebp-4h]

  v12 = this;
  v13[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::CreateSurface", v13);
  v14 = 0;
  if ( !a2 )
  {
    v5 = -2147024809;
LABEL_3:
    v6 = v5;
    v13[0] = v5;
    goto LABEL_4;
  }
  if ( !*((uint32_t *)this + 1) )
  {
    v5 = -2147418113;
    goto LABEL_3;
  }
  memset(&v10, 0, sizeof(v10));
  v10.dwWidth = (DWORD)a3;
  v10.dwSize = 124;
  v10.dwFlags = 7;
  v10.ddsCaps.dwCaps = 64;
  v10.dwHeight = a4;
  if ( fPortraitMode() )
    v10.ddsCaps.dwCaps |= 0x800u;
  LOBYTE(v14) = 1;
  v8 = (CSurface *)operator new(0x84u);
  LOBYTE(v14) = 2;
  if ( v8 )
    v9 = CSurface::CSurface(v8);
  else
    v9 = 0;
  *a2 = v9;
  v14 = 0;
  if ( v13[0] >= 0 )
  {
    v13[0] = CSurface::Create((LPDIRECTDRAWSURFACE7 *)*a2, *((struct IDirectDraw7 **)v12 + 1), &v10);
    if ( v13[0] < 0 )
    {
      if ( *a2 )
      {
        CSurface::`scalar deleting destructor'(*a2, 1);
        *a2 = 0;
      }
    }
  }
  v6 = v13[0];
LABEL_4:
  v14 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return v6;
}
