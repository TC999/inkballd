CTimeManager *__thiscall CTimeManager::CTimeManager(CTimeManager *this)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  struct IDirectDrawSurface7Vtbl *lpVtbl; // edi
  struct IDirectDrawSurface7 *v4; // eax
  char *BitmapRect; // [esp-8h] [ebp-40h]
  _BYTE pExceptionObject[12]; // [esp+10h] [ebp-28h] BYREF
  _BYTE v8[8]; // [esp+1Ch] [ebp-1Ch] BYREF
  struct IDirectDrawSurface7 *v9; // [esp+24h] [ebp-14h]
  int v10[3]; // [esp+28h] [ebp-10h] BYREF
  int v11; // [esp+34h] [ebp-4h]

  *(_DWORD *)this = &CTimeManager::`vftable';
  v10[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CTimeManager::CTimeManager", v10);
  *((_DWORD *)this + 1) = 486;
  *((_DWORD *)this + 5) = 486;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 58;
  *((_DWORD *)this + 4) = 42;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 544;
  *((_DWORD *)this + 8) = 42;
  v11 = 0;
  dwTimeDigitWidth = 9;
  dwTopDrawLoc = 13;
  dwLeftDrawDif = 3;
  if ( CTimeManager::InitSurface(this) < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  DDrawSurface = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v9 = DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 109);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast(v9, 0, 0, v4, (LPRECT)BitmapRect, 0);
  *((_DWORD *)this + 9) = -1;
  v11 = -1;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 1;
  *((_DWORD *)this + 14) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return this;
}
