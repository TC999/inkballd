//----- (0100B312) --------------------------------------------------------
void CGameManager::PerformGameUpdate(CGameManager *self)
{
  CGameManager *v1; // esi
  unsigned int v2; // edx
  int v3; // eax
  unsigned int v4; // eax
  unsigned int Score; // eax
  int v6; // eax
  int v7; // eax
  int GoldVersionOfTile; // eax
  int v9; // eax
  struct tagRECT *v10; // [esp-8h] [ebp-18h]
  struct tagRECT *v11; // [esp-8h] [ebp-18h]
  struct tagRECT *BitmapRect; // [esp-8h] [ebp-18h]
  struct tagRECT *v13; // [esp-8h] [ebp-18h]
  DWORD Time; // [esp+8h] [ebp-8h]

  v1 = self;
  if ( *((_DWORD *)self + 1) )
  {
    Time = timeGetTime();
    v2 = (Time - *(_DWORD *)v1) % 0x42;
    if ( v2 )
    {
      v3 = *((_DWORD *)v1 + 4);
      if ( v3 )
      {
        if ( v3 == 2 )
        {
          dword_10B0640 += v2;
          if ( (unsigned int)dword_10B0640 > 0x14 )
          {
            v4 = CTimeManager::GetTime(*((CTimeManager **)g_pCGameBoard + 2479));
            if ( !v4 || v4 == -1 )
            {
              ++*((_DWORD *)v1 + 3);
              dword_10B062C = 0;
              dword_10B0618 = 0;
              dword_10B0600 = 0;
              dword_10B0604 = 0;
              Sleep(0x5DCu);
              CGameManager::UpdateTime(v1);
              LoadNextLevel();
              *((_DWORD *)v1 + 4) = 0;
            }
            else
            {
              if ( v4 <= 0x3E8 )
                CTimeManager::SetTime(*((CTimeManager **)g_pCGameBoard + 2479), 0);
              else
                CTimeManager::SetTime(*((CTimeManager **)g_pCGameBoard + 2479), v4 - 1000);
              CDisplay::Blt(
                g_pDisplay,
                *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2479) + 4),
                *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2479) + 8),
                g_pTimeManagerSurface,
                0);
              CUIBarObject::GetBoundingRect(*((CUIBarObject **)g_pCGameBoard + 2479), &stru_10B0630);
              if ( CDisplay::Present(g_pDisplay, &stru_10B0630) == -2005532222 )
                CGameBoard::RestoreSurfaces(g_pCGameBoard);
              CScoreManager::IncrementScore(*((CScoreManager **)g_pCGameBoard + 2477), 1);
              CDisplay::Blt(
                g_pDisplay,
                *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2477) + 4),
                *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2477) + 8),
                g_pScoreManagerSurface,
                0);
              CUIBarObject::GetBoundingRect(*((CUIBarObject **)g_pCGameBoard + 2477), &stru_10B0630);
              if ( CDisplay::Present(g_pDisplay, &stru_10B0630) == -2005532222 )
                CGameBoard::RestoreSurfaces(g_pCGameBoard);
              Score = CScoreManager::GetScore(*((CScoreManager **)g_pCGameBoard + 2477));
              CTileManager::SetTiles(*((CTileManager **)g_pCGameBoard + 2478), Score);
              CDisplay::Blt(
                g_pDisplay,
                *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2478) + 4),
                *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2478) + 8),
                g_pTileManagerSurface,
                0);
              CUIBarObject::GetBoundingRect(*((CUIBarObject **)g_pCGameBoard + 2478), &stru_10B0630);
              if ( CDisplay::Present(g_pDisplay, &stru_10B0630) == -2005532222 )
                CGameBoard::RestoreSurfaces(g_pCGameBoard);
              if ( dword_10B062C )
              {
                CDisplay::BltInk(g_pDisplay, &stru_10B061C);
                if ( CDisplay::Present(g_pDisplay, &stru_10B061C) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
              }
              if ( dword_10B0618 )
              {
                CDisplay::BltInk(g_pDisplay, &stru_10B0608);
                if ( CDisplay::Present(g_pDisplay, &stru_10B0608) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
              }
              if ( dword_10B0604 )
              {
                if ( dword_10B0604 == 1 )
                {
                  dword_10B062C = (uintptr_t)CGameBoard::GetTileByIndices(
                                    g_pCGameBoard,
                                    *((_DWORD *)g_pCGameBoard + 2469) - 1,
                                    dword_10B0600);
                  dword_10B0618 = (uintptr_t)CGameBoard::GetTileByIndices(
                                    g_pCGameBoard,
                                    0,
                                    *((_DWORD *)g_pCGameBoard + 2470) - dword_10B0600 - 1);
                  CBoardObject::GetBoundingRect((void*)dword_10B062C, &stru_10B061C);
                  CBoardObject::GetBoundingRect((void*)dword_10B0618, &stru_10B0608);
                  GoldVersionOfTile = GetGoldVersionOfTile(*((_DWORD *)dword_10B062C + 9));
                  BitmapRect = (struct tagRECT *)GetBitmapRect(GoldVersionOfTile);
                  CDisplay::Blt(
                    g_pDisplay,
                    (unsigned __int64)*((double *)dword_10B062C + 1),
                    (unsigned __int64)*((double *)dword_10B062C + 2),
                    g_pGamePiecesSurface,
                    BitmapRect);
                  if ( CDisplay::Present(g_pDisplay, &stru_10B061C) == -2005532222 )
                    CGameBoard::RestoreSurfaces(g_pCGameBoard);
                  v9 = GetGoldVersionOfTile(*((_DWORD *)dword_10B0618 + 9));
                  v13 = (struct tagRECT *)GetBitmapRect(v9);
                  CDisplay::Blt(
                    g_pDisplay,
                    (unsigned __int64)*((double *)dword_10B0618 + 1),
                    (unsigned __int64)*((double *)dword_10B0618 + 2),
                    g_pGamePiecesSurface,
                    v13);
                  if ( CDisplay::Present(g_pDisplay, &stru_10B0608) == -2005532222 )
                    CGameBoard::RestoreSurfaces(g_pCGameBoard);
                  ++dword_10B0600;
                  v1 = self;
                  if ( dword_10B0600 >= *((_DWORD *)g_pCGameBoard + 2470) )
                  {
                    dword_10B0600 = 0;
                    dword_10B0604 = 0;
                  }
                }
                else
                {
                  v1 = self;
                }
              }
              else
              {
                dword_10B062C = (uintptr_t)CGameBoard::GetTileByIndices(g_pCGameBoard, dword_10B0600, 0);
                dword_10B0618 = (uintptr_t)CGameBoard::GetTileByIndices(
                                  g_pCGameBoard,
                                  *((_DWORD *)g_pCGameBoard + 2469) - dword_10B0600 - 1,
                                  *((_DWORD *)g_pCGameBoard + 2470) - 1);
                CBoardObject::GetBoundingRect((void*)dword_10B062C, &stru_10B061C);
                CBoardObject::GetBoundingRect((void*)dword_10B0618, &stru_10B0608);
                v6 = GetGoldVersionOfTile(*((_DWORD *)dword_10B062C + 9));
                v10 = (struct tagRECT *)GetBitmapRect(v6);
                CDisplay::Blt(
                  g_pDisplay,
                  (unsigned __int64)*((double *)dword_10B062C + 1),
                  (unsigned __int64)*((double *)dword_10B062C + 2),
                  g_pGamePiecesSurface,
                  v10);
                if ( CDisplay::Present(g_pDisplay, &stru_10B061C) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
                v7 = GetGoldVersionOfTile(*((_DWORD *)dword_10B0618 + 9));
                v11 = (struct tagRECT *)GetBitmapRect(v7);
                CDisplay::Blt(
                  g_pDisplay,
                  (unsigned __int64)*((double *)dword_10B0618 + 1),
                  (unsigned __int64)*((double *)dword_10B0618 + 2),
                  g_pGamePiecesSurface,
                  v11);
                if ( CDisplay::Present(g_pDisplay, &stru_10B0608) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
                ++dword_10B0600;
                 v1 = self;
                if ( dword_10B0600 >= *((_DWORD *)g_pCGameBoard + 2469) )
                {
                  dword_10B0600 = 0;
                  dword_10B0604 = 1;
                }
              }
            }
            dword_10B0640 = 0;
          }
        }
      }
      else
      {
        CGameBoard::PerformUpdate(g_pCGameBoard, v2, 0);
      }
      *(_DWORD *)v1 = Time;
    }
  }
  else
  {
    CGameManager::UpdateTime(self);
  }
}
