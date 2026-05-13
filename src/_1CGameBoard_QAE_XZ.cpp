#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void Dtor_CGameBoard(CGameBoard *self)
{
  CBallManager *v2; // ecx
  CScoreManager *v3; // ecx
  CInk **v4; // esi
  uint8_t v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::~CGameBoard", 0);
  v2 = (CBallManager *)*((uint32_t *)self + 2476);
  v6 = 0;
  if ( v2 )
  {
    CBallManager::`scalar deleting destructor'(v2, 1);
    *((uint32_t *)self + 2476) = 0;
  }
  v3 = (CScoreManager *)*((uint32_t *)self + 2477);
  if ( v3 )
  {
    CScoreManager::`scalar deleting destructor'(v3, 1);
    *((uint32_t *)self + 2477) = 0;
  }
  if ( *((uint32_t *)self + 2478) )
  {
    operator delete(*((void**)self + 2478));
    *((uint32_t *)self + 2478) = 0;
  }
  if ( *((uint32_t *)self + 2479) )
  {
    operator delete(*((void**)self + 2479));
    *((uint32_t *)self + 2479) = 0;
  }
  if ( g_pGamePiecesSurface )
  {
    CSurface::`scalar deleting destructor'(g_pGamePiecesSurface, 1);
    g_pGamePiecesSurface = 0;
  }
  CGameBoard::FreeDirectDraw(self);
  v4 = (CInk **)(reinterpret_cast<char*>(self) + 9924);
  if ( *v4 )
  {
    CInk::`scalar deleting destructor'(*v4, 1);
    *v4 = 0;
  }
  v6 = -1;
  ((Helpers::CLogBlock*)v5)->~CLogBlock();
}

