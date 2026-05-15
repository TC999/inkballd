#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

CGameBoard* Ctor_CGameBoard(uint32_t *self, HWND a2, void*a3)
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

  v21 = self;
  v4 = 0;
  v22[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CGameBoard::CGameBoard", v22);
  self[2480] = (uint32_t)(uintptr_t)a2;
  v23 = 0;
  self[2475] = (uint32_t)(uintptr_t)a3;
  if ( a3 == (void*)1 )
    v5 = 1.0;
  else
    v5 = 2.0;
  dSizeFactor = v5;
  self[2465] = 544;
  self[2468] = 42;
  self[1016] = 544;
  self[1017] = 42;
  self[2466] = 586;
  self[2467] = 0;
  self[1014] = 0;
  self[1015] = 0;
  self[1010] = (int)(0.0 / dSizeFactor);
  self[1012] = (int)(544.0 / dSizeFactor);
  self[1011] = (int)(42.0 / dSizeFactor);
  self[1013] = (int)(586.0 / dSizeFactor);
  self[2469] = 17;
  self[2470] = 17;
  self[2471] = 24;
  self[2472] = 32;
  self[2473] = 0;
  self[2474] = 0;
  self[0] = 0;
  memset(&self[1], 0, 0x4B0u);
  self[301] = 0;
  memset(&self[302], 0, 0x100u);
  self[366] = 0;
  memset(&self[367], 0, 0x484u);
  self[656] = 0;
  memset(&self[657], 0, 0x100u);
  memset(&self[721], 0, 0x484u);
  self[1018] = 0;
  self[2175] = 0;
  v6 = _time(0);
  _srand(v6);
  v22[0] = CGameBoard::InitDirectDraw((CGameBoard *)self);
  if ( v22[0] < 0 )
  {
    throw std::bad_alloc();
  }
  v22[0] = CDisplay::CreateSurfaceFromBitmap(g_pDisplay, &g_pGamePiecesSurface, (HINSTANCE)0x1F5, 0x17Du, 0x190u);
  if ( v22[0] < 0 )
  {
    throw std::bad_alloc();
  }
  v22[0] = CSurface::SetColorKey(g_pGamePiecesSurface, 0xFF00FFu);
  self[2481] = 0;
  self[2476] = 0;
  self[2477] = 0;
  self[2478] = 0;
  self[2479] = 0;
  LOBYTE(v23) = 1;
  v8 = (CInk *)operator new(0x14u);
  LOBYTE(v23) = 2;
  if ( v8 )
    v9 = (v8 ? new (v8) CInk(a2) : 0);
  else
    v9 = 0;
  LOBYTE(v23) = 1;
  self[2481] = (uint32_t)(uintptr_t)v9;
  v10 = (CBallManager *)operator new(0x518u);
  LOBYTE(v23) = 3;
  if ( v10 )
    v11 = (v10 ? new (v10) CBallManager() : 0);
  else
    v11 = 0;
  LOBYTE(v23) = 1;
  self[2476] = (uint32_t)(uintptr_t)v11;
  v12 = (CScoreManager *)operator new(0x2Cu);
  LOBYTE(v23) = 4;
  if ( v12 )
    v13 = (v12 ? new (v12) CScoreManager() : 0);
  else
    v13 = 0;
  LOBYTE(v23) = 1;
  self[2477] = (uint32_t)(uintptr_t)v13;
  v14 = (CTileManager *)operator new(0x30u);
  LOBYTE(v23) = 5;
  if ( v14 )
    v15 = (v14 ? new (v14) CTileManager() : 0);
  else
    v15 = 0;
  LOBYTE(v23) = 1;
  self[2478] = (uint32_t)(uintptr_t)v15;
  v16 = (CTimeManager *)operator new(0x3Cu);
  LOBYTE(v23) = 6;
  if ( v16 )
    v4 = (v16 ? new (v16) CTimeManager() : 0);
  v23 = -1;
  self[2479] = (uint32_t)(uintptr_t)v4;
  ((Helpers::CLogBlock*)v20)->~CLogBlock();
  return (CGameBoard*)self;
}

void Dtor_CGameBoard(CGameBoard* self)
{
    CBallManager* v2; // ecx
    CScoreManager* v3; // ecx
    CInk** v4; // esi
    uint8_t v5[16]; // [esp+10h] [ebp-14h] BYREF
    int v6; // [esp+20h] [ebp-4h]

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)v5, "CGameBoard::~CGameBoard", 0);
    v2 = (CBallManager*)*((uint32_t*)self + 2476);
    v6 = 0;
    if (v2)
    {
        CBallManager::scalar_deleting_destructor(v2, 1);
        *((uint32_t*)self + 2476) = 0;
    }
    v3 = (CScoreManager*)*((uint32_t*)self + 2477);
    if (v3)
    {
        CScoreManager::scalar_deleting_destructor(v3, 1);
        *((uint32_t*)self + 2477) = 0;
    }
    if (*((uint32_t*)self + 2478))
    {
        operator delete(*((void**)self + 2478));
        *((uint32_t*)self + 2478) = 0;
    }
    if (*((uint32_t*)self + 2479))
    {
        operator delete(*((void**)self + 2479));
        *((uint32_t*)self + 2479) = 0;
    }
    if (g_pGamePiecesSurface)
    {
        CSurface::scalar_deleting_destructor(g_pGamePiecesSurface, 1);
        g_pGamePiecesSurface = 0;
    }
    CGameBoard::FreeDirectDraw(self);
    v4 = (CInk**)(reinterpret_cast<char*>(self) + 9924);
    if (*v4)
    {
        CInk_scalar_deleting_destructor(*v4, 1);
        *v4 = 0;
    }
    v6 = -1;
    ((Helpers::CLogBlock*)v5)->~CLogBlock();
}