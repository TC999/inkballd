#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int CDisplay::Blt(CDisplay *this, uint32_t a2, uint32_t a3, CSurface*a4, struct tagRECT *a5)
{
  int v7; // eax
  int v8; // esi
  uint32_t v10; // [esp-4h] [ebp-2Ch]
  uint8_t v11[8]; // [esp+10h] [ebp-18h] BYREF
  int v12[3]; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  v12[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::Blt", v12);
  v13 = 0;
  if ( !a4 )
    v12[0] = -2147024809;
  v10 = CSurface::IsColorKeyed(a4) != 0;
  DDrawSurface = CSurface::GetDDrawSurface(a4);
  v7 = CDisplay::Blt(this, a2, a3, DDrawSurface, a5, v10);
  v13 = -1;
  v12[0] = v7;
  v8 = v7;
  ((Helpers::CLogBlock*)v11)->~CLogBlock();
  return v8;
}

