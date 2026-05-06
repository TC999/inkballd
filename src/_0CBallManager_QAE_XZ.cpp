CBallManager *__thiscall CBallManager::CBallManager(CBallManager *this)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  struct IDirectDrawSurface7Vtbl *lpVtbl; // edi
  struct IDirectDrawSurface7 *v4; // eax
  void *v5; // ecx
  CBall *v6; // ecx
  char *BitmapRect; // [esp-Ch] [ebp-50h]
  _BYTE pExceptionObject[12]; // [esp+10h] [ebp-34h] BYREF
  _BYTE v10[8]; // [esp+1Ch] [ebp-28h] BYREF
  void *v11; // [esp+24h] [ebp-20h]
  CBallManager *v12; // [esp+28h] [ebp-1Ch]
  int v13; // [esp+2Ch] [ebp-18h] BYREF
  int v14; // [esp+30h] [ebp-14h]
  int v15; // [esp+40h] [ebp-4h]

  v12 = this;
  *(_DWORD *)this = &CBallManager::`vftable';
  v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBallManager::CBallManager", &v13);
  *((_DWORD *)this + 3) = 104;
  *((_DWORD *)this + 7) = 104;
  v15 = 0;
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
  v14 = (int)DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 106);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v13 = lpVtbl->Blt((IDirectDrawSurface7 *)v14, (LPRECT)((char *)this + 20), v4, (LPRECT)BitmapRect, 0, 0);
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 4;
  *((_DWORD *)this + 323) = 0;
  *((_DWORD *)this + 324) = 150;
  *((_DWORD *)this + 325) = 150;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  v14 = 0;
  LOBYTE(v15) = 1;
  while ( v14 < 6 )
  {
    v5 = operator new(0x1A8u);
    v11 = v5;
    LOBYTE(v15) = 2;
    if ( v5 )
      v6 = (CBall *)CBall::CBall((int)v5, 0, 0, 0, 18);
    else
      v6 = 0;
    LOBYTE(v15) = 1;
    *((_DWORD *)this + v14 + 14) = v6;
    if ( v6 )
      CBall::AddRef(v6);
    ++v14;
  }
  *((_DWORD *)this + 20) = 0;
  memset((char *)this + 84, 0, 0x484u);
  v15 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return this;
}
