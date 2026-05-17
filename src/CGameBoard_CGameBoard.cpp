//----- (01008F80) --------------------------------------------------------
CGameBoard *__thiscall CGameBoard::CGameBoard(CGameBoard *this, HWND a2, void *a3)
{
  CTimeManager *v4; // edi
  double v5; // st7
  __time32_t v6; // eax
  _BYTE *v7; // eax
  CInk *v8; // ecx
  CInk *v9; // eax
  CBallManager *v10; // ecx
  CBallManager *v11; // eax
  CScoreManager *v12; // ecx
  CScoreManager *v13; // eax
  CTileManager *v14; // ecx
  CTileManager *v15; // eax
  CTimeManager *v16; // ecx
  _BYTE v18[12]; // [esp+10h] [ebp-38h] BYREF
  _BYTE pExceptionObject[12]; // [esp+1Ch] [ebp-2Ch] BYREF
  const char *v20[3]; // [esp+28h] [ebp-20h] BYREF
  int v21[4]; // [esp+34h] [ebp-14h] BYREF
  int v22; // [esp+44h] [ebp-4h]

  v20[2] = (const char *)this;
  v4 = 0;
  v21[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CGameBoard::CGameBoard", v21);
  *((_DWORD *)this + 2480) = a2;
  v22 = 0;
  *((_DWORD *)this + 2475) = a3;
  if ( a3 == (void *)1 )
    v5 = 1.0;
  else
    v5 = 2.0;
  dSizeFactor = v5;
  *((_DWORD *)this + 2465) = 544;
  *((_DWORD *)this + 2468) = 42;
  *((_DWORD *)this + 1016) = 544;
  *((_DWORD *)this + 1017) = 42;
  *((_DWORD *)this + 2466) = 586;
  *((_DWORD *)this + 2467) = 0;
  *((_DWORD *)this + 1014) = 0;
  *((_DWORD *)this + 1015) = 0;
  *((_DWORD *)this + 1010) = (int)(0.0 / dSizeFactor);
  *((_DWORD *)this + 1012) = (int)(544.0 / dSizeFactor);
  *((_DWORD *)this + 1011) = (int)(42.0 / dSizeFactor);
  *((_DWORD *)this + 1013) = (int)(586.0 / dSizeFactor);
  *((_DWORD *)this + 2469) = 17;
  *((_DWORD *)this + 2470) = 17;
  *((_DWORD *)this + 2471) = 24;
  *((_DWORD *)this + 2472) = 32;
  *((_DWORD *)this + 2473) = 0;
  *((_DWORD *)this + 2474) = 0;
  *(_DWORD *)this = 0;
  memset((char *)this + 4, 0, 0x4B0u);
  *((_DWORD *)this + 301) = 0;
  memset((char *)this + 1208, 0, 0x100u);
  *((_DWORD *)this + 366) = 0;
  memset((char *)this + 1468, 0, 0x484u);
  *((_DWORD *)this + 656) = 0;
  memset((char *)this + 2628, 0, 0x100u);
  memset((char *)this + 2884, 0, 0x484u);
  *((_DWORD *)this + 1018) = 0;
  *((_DWORD *)this + 2175) = 0;
  v6 = _time(0);
  _srand(v6);
  v21[0] = CGameBoard::InitDirectDraw(this);
  if ( v21[0] < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject);
    v7 = pExceptionObject;
    goto LABEL_6;
  }
  v21[0] = CDisplay::CreateSurfaceFromBitmap(g_pDisplay, &g_pGamePiecesSurface, (const WCHAR *)0x1F5, 0x17Du, 400);
  if ( v21[0] < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)v18);
    v7 = v18;
LABEL_6:
    _CxxThrowException(v7, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  v21[0] = CSurface::SetColorKey(g_pGamePiecesSurface, 0xFF00FFu);
  *((_DWORD *)this + 2481) = 0;
  *((_DWORD *)this + 2476) = 0;
  *((_DWORD *)this + 2477) = 0;
  *((_DWORD *)this + 2478) = 0;
  *((_DWORD *)this + 2479) = 0;
  LOBYTE(v22) = 1;
  v8 = (CInk *)operator new(0x14u);
  LOBYTE(v22) = 2;
  if ( v8 )
    v9 = CInk::CInk(v8, a2);
  else
    v9 = 0;
  LOBYTE(v22) = 1;
  *((_DWORD *)this + 2481) = v9;
  v10 = (CBallManager *)operator new(0x518u);
  LOBYTE(v22) = 3;
  if ( v10 )
    v11 = CBallManager::CBallManager(v10);
  else
    v11 = 0;
  LOBYTE(v22) = 1;
  *((_DWORD *)this + 2476) = v11;
  v12 = (CScoreManager *)operator new(0x2Cu);
  LOBYTE(v22) = 4;
  if ( v12 )
    v13 = CScoreManager::CScoreManager(v12);
  else
    v13 = 0;
  LOBYTE(v22) = 1;
  *((_DWORD *)this + 2477) = v13;
  v14 = (CTileManager *)operator new(0x30u);
  LOBYTE(v22) = 5;
  if ( v14 )
    v15 = CTileManager::CTileManager(v14);
  else
    v15 = 0;
  LOBYTE(v22) = 1;
  *((_DWORD *)this + 2478) = v15;
  v16 = (CTimeManager *)operator new(0x3Cu);
  LOBYTE(v22) = 6;
  if ( v16 )
    v4 = CTimeManager::CTimeManager(v16);
  v22 = -1;
  *((_DWORD *)this + 2479) = v4;
  Helpers::CLogBlock::~CLogBlock(v20);
  return this;
}
