#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void DrawToSurface_CTileManager(CTileManager* self)
{
    IDirectDrawSurface7* DDrawSurface;
    IDirectDrawSurface7* ddraw_source;
    IDirectDrawSurface7Vtbl* lpVtbl;
    uint32_t v17;
    uint32_t v3;
    uint32_t v4;
    uint32_t v5;
    uint32_t v6;
  uint32_t v7;
  RECT* BitmapRect;
  char* v12;
  char* v13;
  uint8_t v14[8];
  uint32_t v15;
  CTileManager *v16;
  int v18;

  v16 = self;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v14), "CTileManager::DrawToSurface", 0);
  DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTileManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v17 = (uint32_t)DDrawSurface;
  BitmapRect = (RECT*)CBitmapRects::GetBitmapRect(g_CBitmapRects, 108);
  v3 = (uint32_t)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast((IDirectDrawSurface7*)v17, 0, 0, (IDirectDrawSurface7*)v3, BitmapRect, 0);
  if ( *((uint32_t *)v16 + 9) <= 0x63u )
  {
    v17 = *((uint32_t *)v16 + 9);
    v18 = 14;
    do
    {
      v7 = v17 % 0xA + 134;
      v17 = v17 / 0xA;
      v15 = v7;
      ddraw_source = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTileManagerSurface);
      v13 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v15);
      v3 = (uint32_t)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
      ddraw_source->lpVtbl->BltFast(ddraw_source, v18, 18, (IDirectDrawSurface7*)v3, (RECT*)v13, 0);
      v18 -= 9;
    }
    while ( v17 );
  }
  else
  {
    v4 = (uint32_t)CSurface::GetDDrawSurface(g_pTileManagerSurface);
    DDrawSurface = (IDirectDrawSurface7*)v4;
    v12 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 144);
    v6 = (uint32_t)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    DDrawSurface->lpVtbl->BltFast(DDrawSurface, 14, 18, (IDirectDrawSurface7*)v6, (RECT*)v12, 0);
  }
  AddDisplayUpdateRect((struct tagRECT *)((char*)v16 + 20));
  reinterpret_cast<Helpers::CLogBlock*>(v14)->~CLogBlock();
}
