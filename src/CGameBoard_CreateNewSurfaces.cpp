//----- (01008C38) --------------------------------------------------------
int __thiscall CGameBoard::CreateNewSurfaces(CGameBoard *this)
{
  char *v2; // ecx
  LPVOID *v3; // edi
  CSurface *v4; // edi
  CSurface *v5; // edi
  CSurface *v6; // edi
  CSurface *v7; // edi
  int v8; // esi
  const char *v10[4]; // [esp+10h] [ebp-24h] BYREF
  int v11[4]; // [esp+20h] [ebp-14h] BYREF
  int v12; // [esp+30h] [ebp-4h]

  v10[3] = (const char *)this;
  v11[0] = -2147024882;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::CreateNewSurfaces", v11);
  v12 = 1;
  v2 = (char *)operator new(0x38u);
  v10[2] = v2;
  LOBYTE(v12) = 2;
  if ( v2 )
    v3 = (LPVOID *)CDisplay::CDisplay((CDisplay *)v2);
  else
    v3 = 0;
  v12 = 0;
  if ( v3 )
  {
    v11[0] = CDisplay::CreateWindowedDisplay(
               v3,
               *((HWND *)this + 2480),
               *((_DWORD *)this + 2465),
               *((_DWORD *)this + 2466));
    if ( v11[0] < 0 )
    {
      CDisplay::`scalar deleting destructor'((CDisplay *)v3, 1);
    }
    else
    {
      if ( g_pDisplay )
        CDisplay::`scalar deleting destructor'(g_pDisplay, 1);
      g_pDisplay = (CDisplay *)v3;
    }
  }
  if ( v11[0] >= 0 )
  {
    v4 = g_pBallManagerSurface;
    v11[0] = CBallManager::InitSurface(*((CBallManager **)this + 2476));
    if ( v11[0] < 0 )
    {
      g_pBallManagerSurface = v4;
    }
    else if ( v4 )
    {
      CSurface::`scalar deleting destructor'(v4, 1);
    }
    if ( v11[0] >= 0 )
    {
      v5 = g_pScoreManagerSurface;
      v11[0] = CScoreManager::InitSurface(*((CScoreManager **)this + 2477));
      if ( v11[0] < 0 )
      {
        g_pScoreManagerSurface = v5;
      }
      else if ( v5 )
      {
        CSurface::`scalar deleting destructor'(v5, 1);
      }
      if ( v11[0] >= 0 )
      {
        v6 = g_pTileManagerSurface;
        v11[0] = CTileManager::InitSurface(*((CTileManager **)this + 2478));
        if ( v11[0] < 0 )
        {
          g_pTileManagerSurface = v6;
        }
        else if ( v6 )
        {
          CSurface::`scalar deleting destructor'(v6, 1);
        }
        if ( v11[0] >= 0 )
        {
          v7 = g_pTimeManagerSurface;
          v11[0] = CTimeManager::InitSurface(*((CTimeManager **)this + 2479));
          if ( v11[0] < 0 )
          {
            g_pTimeManagerSurface = v7;
          }
          else if ( v7 )
          {
            CSurface::`scalar deleting destructor'(v7, 1);
          }
        }
      }
    }
  }
  v8 = v11[0];
  v12 = -1;
  Helpers::CLogBlock::~CLogBlock(v10);
  return v8;
}
