#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int __thiscall CGameBoard::RestoreSurfaces(CScoreManager **this)
{
  int v3; // esi
  int v9; // eax
  uint8_t v10[8]; // [esp+10h] [ebp-20h] BYREF
  CSurface *v11; // [esp+18h] [ebp-18h] BYREF
  int v13[3]; // [esp+20h] [ebp-10h] BYREF
  int v14; // [esp+2Ch] [ebp-4h]

  v13[0] = -2147467259;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::RestoreSurfaces", v13);
  v14 = 0;
  v12 = 0;
  DirectDraw = CDisplay::GetDirectDraw(g_pDisplay);
  v3 = DirectDraw->lpVtbl->RestoreAllSurfaces(DirectDraw);
  v13[0] = v3;
  if ( v3 >= 0 )
  {
    BoardBuffer = CDisplay::GetBoardBuffer(g_pDisplay);
    BoardBuffer->lpVtbl->Restore(BoardBuffer);
    InkBuffer = CDisplay::GetInkBuffer(g_pDisplay);
    InkBuffer->lpVtbl->Restore(InkBuffer);
    BackBuffer = CDisplay::GetBackBuffer(g_pDisplay);
    BackBuffer->lpVtbl->Restore(BackBuffer);
    FrontBuffer = CDisplay::GetFrontBuffer(g_pDisplay);
    FrontBuffer->lpVtbl->Restore(FrontBuffer);
    v9 = CDisplay::CreatePaletteFromBitmap(g_pDisplay, &v12, (const uint16_t *)0x1F5);
    v13[0] = v9;
    if ( v9 >= 0 )
    {
      CDisplay::SetPalette(g_pDisplay, v12);
      if ( v12 )
      {
        (*(void (__stdcall **)(struct IDirectDrawPalette *))(*(uint32_t *)v12 + 8))(v12);
        v12 = 0;
      }
      v3 = CDisplay::CreateSurfaceFromBitmap(g_pDisplay, &v11, (HINSTANCE)0x1F5, 0x17Du, 0x190u);
      v13[0] = v3;
      if ( v3 >= 0 )
      {
        if ( g_pGamePiecesSurface )
          CSurface::scalar_deleting_destructor(g_pGamePiecesSurface, 1);
        g_pGamePiecesSurface = v11;
        v3 = CSurface::SetColorKey(v11, 0xFF00FFu);
        v13[0] = v3;
        if ( v3 >= 0 )
        {
          CScoreManager::Restore(this[2477]);
          CTileManager::Restore(this[2478]);
          CBallManager::Restore(this[2476]);
          CTimeManager::Restore(this[2479]);
          CGameBoard::RedrawBoardBuffer((CGameBoard *)this);
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
