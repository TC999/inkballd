//----- (010095CF) --------------------------------------------------------
int CGameBoard::RestoreSurfaces(CGameBoard *self)
{
  struct IDirectDraw7 *DirectDraw; // eax
  int v3; // esi
  struct IDirectDrawSurface7 *BoardBuffer; // eax
  struct IDirectDrawSurface7 *InkBuffer; // eax
  struct IDirectDrawSurface7 *BackBuffer; // eax
  struct IDirectDrawSurface7 *FrontBuffer; // eax
  int v9; // eax
  _BYTE v10[8]; // [esp+10h] [ebp-20h] BYREF
  CSurface *v11; // [esp+18h] [ebp-18h] BYREF
  struct IDirectDrawPalette *v12; // [esp+1Ch] [ebp-14h] BYREF
  int v13[3]; // [esp+20h] [ebp-10h] BYREF
  int v14; // [esp+2Ch] [ebp-4h]

  v13[0] = -2147467259;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::RestoreSurfaces", v13);
  v14 = 0;
  v12 = 0;
  DirectDraw = (struct IDirectDraw7 *)CDisplay::GetDirectDraw(g_pDisplay);
  v3 = DirectDraw->lpVtbl->RestoreAllSurfaces(DirectDraw);
  v13[0] = v3;
  if ( v3 >= 0 )
  {
    BoardBuffer = (struct IDirectDrawSurface7 *)CDisplay::GetBoardBuffer(g_pDisplay);
    BoardBuffer->lpVtbl->Restore(BoardBuffer);
    InkBuffer = (struct IDirectDrawSurface7 *)CDisplay::GetInkBuffer(g_pDisplay);
    InkBuffer->lpVtbl->Restore(InkBuffer);
    BackBuffer = (struct IDirectDrawSurface7 *)CDisplay::GetBackBuffer(g_pDisplay);
    BackBuffer->lpVtbl->Restore(BackBuffer);
    FrontBuffer = (struct IDirectDrawSurface7 *)CDisplay::GetFrontBuffer(g_pDisplay);
    FrontBuffer->lpVtbl->Restore(FrontBuffer);
    v9 = CDisplay::CreatePaletteFromBitmap(g_pDisplay, (void **)&v12, (const WCHAR *)0x1F5);
    v13[0] = v9;
    if ( v9 >= 0 )
    {
      CDisplay::SetPalette(g_pDisplay, v12);
      if ( v12 )
      {
        (*(void (__stdcall **)(struct IDirectDrawPalette *))(*(_DWORD *)v12 + 8))(v12);
        v12 = 0;
      }
      v3 = CDisplay::CreateSurfaceFromBitmap(g_pDisplay, (void **)&v11, (void*)(uintptr_t)0x1F5, 0x17Du, 0x190u);
      v13[0] = v3;
      if ( v3 >= 0 )
      {
        if ( g_pGamePiecesSurface )
          delete g_pGamePiecesSurface;
        g_pGamePiecesSurface = v11;
        v3 = CSurface::SetColorKey(v11, 0xFF00FFu);
        v13[0] = v3;
        if ( v3 >= 0 )
        {
          CScoreManager::Restore(*(CScoreManager **)((uint32_t *)self + 2477));
          CTileManager::Restore(*(CTileManager **)((uint32_t *)self + 2478));
          CBallManager::Restore(*(CBallManager **)((uint32_t *)self + 2476));
          CTimeManager::Restore(*(CTimeManager **)((uint32_t *)self + 2479));
          CGameBoard::RedrawBoardBuffer((CGameBoard *)self);
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
