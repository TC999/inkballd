#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int RestoreSurfaces_CGameBoard(CGameBoard *self)
{
    IDirectDraw7* DirectDraw;
    void* BoardBuffer;
    IDirectDrawSurface7* InkBuffer;
    IDirectDrawSurface7* BackBuffer;
    IDirectDrawSurface7* FrontBuffer;
    IDirectDrawPalette* palette;
  int v3;
  int v9;
  uint8_t v10[8];
  CSurface *v11;
  int v13[3];
  int v14;

  v13[0] = -2147467259;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::RestoreSurfaces", v13);
  v14 = 0;
  palette = 0;
  DirectDraw = (IDirectDraw7*)CDisplay::GetDirectDraw(g_pDisplay);
  v3 = DirectDraw->lpVtbl->RestoreAllSurfaces(DirectDraw);
  v13[0] = v3;
  if ( v3 >= 0 )
  {
    BoardBuffer = CDisplay::GetBoardBuffer(g_pDisplay);
    InkBuffer = (IDirectDrawSurface7*)CDisplay::GetInkBuffer(g_pDisplay);
    InkBuffer->lpVtbl->Restore(InkBuffer);
    BackBuffer = (IDirectDrawSurface7*)CDisplay::GetBackBuffer(g_pDisplay);
    BackBuffer->lpVtbl->Restore(BackBuffer);
    FrontBuffer = (IDirectDrawSurface7*)CDisplay::GetFrontBuffer(g_pDisplay);
    FrontBuffer->lpVtbl->Restore(FrontBuffer);
    v9 = CDisplay::CreatePaletteFromBitmap(g_pDisplay, &palette, (const WCHAR*)(uintptr_t)0x1F5);
    v13[0] = v9;
    if ( v9 >= 0 )
    {
      CDisplay::SetPalette(g_pDisplay, palette);
      if ( palette )
      {
        (*(void (__stdcall **)(IDirectDrawPalette*))(*(uint32_t *)palette + 8))(palette);
        palette = 0;
      }
      v3 = CDisplay::CreateSurfaceFromBitmap(g_pDisplay, (void**)&v11, 0x1F5, 0x17Du, 0x190u);
      v13[0] = v3;
      if ( v3 >= 0 )
      {
        if ( g_pGamePiecesSurface )
          CSurface::scalar_deleting_destructor((CSurface*)g_pGamePiecesSurface, 1);
        g_pGamePiecesSurface = v11;
        v3 = CSurface::SetColorKey(v11, 0xFF00FFu);
        v13[0] = v3;
        if ( v3 >= 0 )
        {
          uint32_t* base = (uint32_t*)self;
          CScoreManager::Restore((CScoreManager*)base[2477]);
          CTileManager::Restore((CTileManager*)base[2478]);
          CBallManager::Restore((CBallManager*)base[2476]);
          CTimeManager::Restore((CTimeManager*)base[2479]);
          CGameBoard::RedrawBoardBuffer(self);
          v13[0] = 0;
          v3 = 0;
        }
      }
    }
    else
    {
      v3 = v9;
    }
  }
  v14 = -1;
  ((Helpers::CLogBlock *)v10)->~CLogBlock();
  return v3;
}
