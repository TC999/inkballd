#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
uint32_t *CGameBoard::CGameBoard(uint32_t *this, HWND a2, void*a3)
{
  CTimeManager *v4; // edi
  double v5; // st7
  __time32_t v6; // eax
  uint8_t *v7; // eax
  CInk *v8; // ecx
  CInk *v9; // eax
  CBallManager *v10; // ecx
  CBallManager *v11; // eax
  CScoreManager *v12; // ecx
  CScoreManager *v13; // eax
  CTileManager *v14; // ecx
  CTileManager *v15; // eax
  CTimeManager *v16; // ecx
  uint8_t v18[12]; // [esp+10h] [ebp-38h] BYREF
  uint8_t pExceptionObject[12]; // [esp+1Ch] [ebp-2Ch] BYREF
  uint8_t v20[8]; // [esp+28h] [ebp-20h] BYREF
  uint32_t *v21; // [esp+30h] [ebp-18h]
  int v22[4]; // [esp+34h] [ebp-14h] BYREF
  int v23; // [esp+44h] [ebp-4h]

  v21 = this;
  v4 = 0;
  v22[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CGameBoard::CGameBoard", v22);
  this[2480] = a2;
  v23 = 0;
  this[2475] = a3;
  if ( a3 == (void*)1 )
    v5 = 1.0;
  else
    v5 = 2.0;
  dSizeFactor = v5;
  this[2465] = 544;
  this[2468] = 42;
  this[1016] = 544;
  this[1017] = 42;
  this[2466] = 586;
  this[2467] = 0;
  this[1014] = 0;
  this[1015] = 0;
  this[1010] = (int)(0.0 / dSizeFactor);
  this[1012] = (int)(544.0 / dSizeFactor);
  this[1011] = (int)(42.0 / dSizeFactor);
  this[1013] = (int)(586.0 / dSizeFactor);
  this[2469] = 17;
  this[2470] = 17;
  this[2471] = 24;
  this[2472] = 32;
  this[2473] = 0;
  this[2474] = 0;
  *this = 0;
  memset(this + 1, 0, 0x4B0u);
  this[301] = 0;
  memset(this + 302, 0, 0x100u);
  this[366] = 0;
  memset(this + 367, 0, 0x484u);
  this[656] = 0;
  memset(this + 657, 0, 0x100u);
  memset(this + 721, 0, 0x484u);
  this[1018] = 0;
  this[2175] = 0;
  v6 = _time(0);
  _srand(v6);
  v22[0] = CGameBoard::InitDirectDraw((CGameBoard *)this);
  if ( v22[0] < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject);
    v7 = pExceptionObject;
    goto LABEL_6;
  }
  v22[0] = CDisplay::CreateSurfaceFromBitmap(g_pDisplay, &g_pGamePiecesSurface, (HINSTANCE)0x1F5, 0x17Du, 0x190u);
  if ( v22[0] < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)v18);
    v7 = v18;
LABEL_6:
    _CxxThrowException(v7, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  v22[0] = CSurface::SetColorKey(g_pGamePiecesSurface, 0xFF00FFu);
  this[2481] = 0;
  this[2476] = 0;
  this[2477] = 0;
  this[2478] = 0;
  this[2479] = 0;
  LOBYTE(v23) = 1;
  v8 = (CInk *)operator new(0x14u);
  LOBYTE(v23) = 2;
  if ( v8 )
    v9 = CInk::CInk(v8, a2);
  else
    v9 = 0;
  LOBYTE(v23) = 1;
  this[2481] = v9;
  v10 = (CBallManager *)operator new(0x518u);
  LOBYTE(v23) = 3;
  if ( v10 )
    v11 = CBallManager::CBallManager(v10);
  else
    v11 = 0;
  LOBYTE(v23) = 1;
  this[2476] = v11;
  v12 = (CScoreManager *)operator new(0x2Cu);
  LOBYTE(v23) = 4;
  if ( v12 )
    v13 = CScoreManager::CScoreManager(v12);
  else
    v13 = 0;
  LOBYTE(v23) = 1;
  this[2477] = v13;
  v14 = (CTileManager *)operator new(0x30u);
  LOBYTE(v23) = 5;
  if ( v14 )
    v15 = CTileManager::CTileManager(v14);
  else
    v15 = 0;
  LOBYTE(v23) = 1;
  this[2478] = v15;
  v16 = (CTimeManager *)operator new(0x3Cu);
  LOBYTE(v23) = 6;
  if ( v16 )
    v4 = CTimeManager::CTimeManager(v16);
  v23 = -1;
  this[2479] = v4;
  ((Helpers::CLogBlock*)v20)->~CLogBlock();
  return this;
}

