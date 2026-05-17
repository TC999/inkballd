//----- (010087BA) --------------------------------------------------------
int CGameBoard::DisplayFrame(CGameBoard *self, int a2, int a3)
{
  int v4; // edi
  struct tagRECT *PlayingAreaRect; // eax
  int v6; // eax
  _DWORD *v8; // ebx
  struct IDirectDrawSurface7 *BackBuffer; // eax
  bool v10; // zf
  struct tagRECT *v11; // ebx
  struct tagRECT v12; // [esp+10h] [ebp-40h] BYREF
  struct tagRECT v13; // [esp+20h] [ebp-30h] BYREF
  _BYTE v14[8]; // [esp+30h] [ebp-20h] BYREF
  _DWORD *v15; // [esp+38h] [ebp-18h]
  char *v16; // [esp+3Ch] [ebp-14h]
  int v17[3]; // [esp+40h] [ebp-10h] BYREF
  int v18; // [esp+4Ch] [ebp-4h]
  int v19; // [esp+5Ch] [ebp+Ch]
  int v20; // [esp+5Ch] [ebp+Ch]

  v4 = 0;
  v17[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CGameBoard::DisplayFrame", v17);
  v18 = 0;
  if ( !BoardIsActive() && !a3 )
    goto LABEL_25;
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_DWORD *)self + 2476) + 4),
    *(_DWORD *)(*((_DWORD *)self + 2476) + 8),
    g_pBallManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_DWORD *)self + 2477) + 4),
    *(_DWORD *)(*((_DWORD *)self + 2477) + 8),
    g_pScoreManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_DWORD *)self + 2478) + 4),
    *(_DWORD *)(*((_DWORD *)self + 2478) + 8),
    g_pTileManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_DWORD *)self + 2479) + 4),
    *(_DWORD *)(*((_DWORD *)self + 2479) + 8),
    g_pTimeManagerSurface,
    0);
  if ( CInk_GetInkUpdateRect(*((CInk **)self + 2481), &v12) )
    CGameBoard::AddDisplayUpdateRect(self, &v12);
  PlayingAreaRect = CGameBoard::GetPlayingAreaRect(self);
  v6 = CDisplay::BltInk(g_pDisplay, PlayingAreaRect);
  v17[0] = v6;
  if ( v6 < 0 )
    goto LABEL_6;
  v19 = 0;
  if ( *((int *)self + 656) > 0 )
  {
    v16 = (char *)self + 2628;
    while ( 1 )
    {
      v8 = *(_DWORD **)v16;
      if ( *(_DWORD *)(*(_DWORD *)v16 + 156) )
        break;
      v10 = v8[40] == 0;
      v15 = v8 + 40;
      if ( !v10 )
      {
        CMovingObject::GetMovementRect((CMovingObject *)v8, &v13);
        *v15 = 0;
LABEL_16:
        CGameBoard::AddDisplayUpdateRect(self, &v13);
      }
LABEL_17:
      ++v19;
      v16 += 4;
      if ( v19 >= *((_DWORD *)self + 656) )
        goto LABEL_18;
    }
    BackBuffer = (struct IDirectDrawSurface7 *)CDisplay::GetBackBuffer(g_pDisplay);
    v6 = CGameBoard::BltBall(self, (CBall *)v8, BackBuffer);
    v17[0] = v6;
    if ( v6 < 0 )
      goto LABEL_6;
    if ( a2 )
      goto LABEL_17;
    CMovingObject::GetMovementRect((CMovingObject *)v8, &v13);
    goto LABEL_16;
  }
LABEL_18:
  if ( !a2 )
  {
    v20 = 0;
    if ( *((int *)self + 1018) > 0 )
    {
      v11 = (struct tagRECT *)((char *)self + 4076);
      do
      {
        v6 = CDisplay::Present(g_pDisplay, v11);
        v17[0] = v6;
        if ( v6 < 0 )
          goto LABEL_6;
        ++v20;
        ++v11;
      }
      while ( v20 < *((_DWORD *)self + 1018) );
    }
LABEL_25:
    v17[0] = 0;
    goto LABEL_7;
  }
  v6 = CDisplay::Present(g_pDisplay, 0);
  v17[0] = v6;
  if ( v6 >= 0 )
    goto LABEL_25;
LABEL_6:
  v4 = v6;
LABEL_7:
  v18 = -1;
  ((Helpers::CLogBlock *)v14)->~CLogBlock();
  return v4;
}
