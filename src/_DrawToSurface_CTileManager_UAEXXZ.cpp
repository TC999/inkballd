#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CTileManager::DrawToSurface(CTileManager *this)
{
  uint32_t v7; // edx
  void (__stdcall **p_BltFast)(struct IDirectDrawSurface7 *, int, int, struct IDirectDrawSurface7 *, char*, uint32_t); // esi
  char*BitmapRect; // [esp-8h] [ebp-3Ch]
  char*v12; // [esp-8h] [ebp-3Ch]
  char*v13; // [esp-8h] [ebp-3Ch]
  uint8_t v14[8]; // [esp+10h] [ebp-24h] BYREF
  uint32_t v15; // [esp+18h] [ebp-1Ch]
  CTileManager *v16; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+24h] [ebp-10h]
  int v19; // [esp+30h] [ebp-4h]

  v16 = this;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CTileManager::DrawToSurface", 0);
  v19 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pTileManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v17 = DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 108);
  v3 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast(v17, 0, 0, v3, (LPRECT)BitmapRect, 0);
  if ( *((uint32_t *)v16 + 9) <= 0x63u )
  {
    v17 = (struct IDirectDrawSurface7 *)*((uint32_t *)v16 + 9);
    v18 = 14;
    do
    {
      v7 = (uint32_t)v17 % 0xA + 134;
      v17 = (struct IDirectDrawSurface7 *)((uint32_t)v17 / 0xA);
      v15 = v7;
      v8 = CSurface::GetDDrawSurface(g_pTileManagerSurface);
      p_BltFast = (void (__stdcall **)(struct IDirectDrawSurface7 *, int, int, struct IDirectDrawSurface7 *, char*, uint32_t))&v8->lpVtbl->BltFast;
      v13 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v15);
      v10 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
      (*p_BltFast)(v8, v18, 18, v10, v13, 0);
      v18 -= 9;
    }
    while ( v17 );
  }
  else
  {
    v4 = CSurface::GetDDrawSurface(g_pTileManagerSurface);
    v5 = v4->lpVtbl;
    v17 = v4;
    v12 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 144);
    v6 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v5->BltFast(v17, 14, 18, v6, (LPRECT)v12, 0);
  }
  AddDisplayUpdateRect((struct tagRECT *)((char*)v16 + 20));
  v19 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
}
