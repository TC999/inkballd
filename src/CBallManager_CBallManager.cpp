//----- (0100560F) --------------------------------------------------------
CBallManager *__thiscall CBallManager::CBallManager(CBallManager *this)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  struct IDirectDrawSurface7Vtbl *lpVtbl; // edi
  struct IDirectDrawSurface7 *v4; // eax
  char *v5; // ecx
  CBall *v6; // ecx
  char *BitmapRect; // [esp-Ch] [ebp-50h]
  _BYTE pExceptionObject[12]; // [esp+10h] [ebp-34h] BYREF
  const char *v10[4]; // [esp+1Ch] [ebp-28h] BYREF
  int v11; // [esp+2Ch] [ebp-18h] BYREF
  int v12; // [esp+30h] [ebp-14h]
  int v13; // [esp+40h] [ebp-4h]

  v10[3] = (const char *)this;
  *(_DWORD *)this = &CBallManager::`vftable';
  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBallManager::CBallManager", &v11);
  *((_DWORD *)this + 3) = 104;
  *((_DWORD *)this + 7) = 104;
  v13 = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 4) = 42;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 8) = 42;
  if ( CBallManager::InitSurface(this) < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  DDrawSurface = CSurface::GetDDrawSurface(g_pBallManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v12 = (int)DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 106);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v11 = lpVtbl->Blt((IDirectDrawSurface7 *)v12, (LPRECT)((char *)this + 20), v4, (LPRECT)BitmapRect, 0, 0);
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 4;
  *((_DWORD *)this + 323) = 0;
  *((_DWORD *)this + 324) = 150;
  *((_DWORD *)this + 325) = 150;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  v12 = 0;
  LOBYTE(v13) = 1;
  while ( v12 < 6 )
  {
    v5 = (char *)operator new(0x1A8u);
    v10[2] = v5;
    LOBYTE(v13) = 2;
    if ( v5 )
      v6 = CBall::CBall((CBall *)v5, 0, 0, 0, 18);
    else
      v6 = 0;
    LOBYTE(v13) = 1;
    *((_DWORD *)this + v12 + 14) = v6;
    if ( v6 )
      CBall::AddRef(v6);
    ++v12;
  }
  *((_DWORD *)this + 20) = 0;
  memset((char *)this + 84, 0, 0x484u);
  v13 = -1;
  Helpers::CLogBlock::~CLogBlock(v10);
  return this;
}
