#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CGameBoard::CreateNewSurfaces(CGameBoard *this)
{
  void*v2; // ecx
  CDisplay *v3; // edi
  CSurface *v4; // edi
  CSurface *v5; // edi
  CSurface *v6; // edi
  CSurface *v7; // edi
  int v8; // esi
  uint8_t v10[8]; // [esp+10h] [ebp-24h] BYREF
  void*v11; // [esp+18h] [ebp-1Ch]
  CGameBoard *v12; // [esp+1Ch] [ebp-18h]
  int v13[4]; // [esp+20h] [ebp-14h] BYREF
  int v14; // [esp+30h] [ebp-4h]

  v12 = this;
  v13[0] = -2147024882;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::CreateNewSurfaces", v13);
  v14 = 1;
  v2 = operator new(0x38u);
  v11 = v2;
  LOBYTE(v14) = 2;
  if ( v2 )
    v3 = CDisplay::CDisplay((CDisplay *)v2);
  else
    v3 = 0;
  v14 = 0;
  if ( v3 )
  {
    v13[0] = CDisplay::CreateWindowedDisplay(
               v3,
               *((HWND *)this + 2480),
               *((uint32_t *)this + 2465),
               *((uint32_t *)this + 2466));
    if ( v13[0] < 0 )
    {
      CDisplay::`scalar deleting destructor'(v3, 1);
    }
    else
    {
      if ( g_pDisplay )
        CDisplay::`scalar deleting destructor'(g_pDisplay, 1);
      g_pDisplay = v3;
    }
  }
  if ( v13[0] >= 0 )
  {
    v4 = g_pBallManagerSurface;
    v13[0] = CBallManager::InitSurface(*((CBallManager **)this + 2476));
    if ( v13[0] < 0 )
    {
      g_pBallManagerSurface = v4;
    }
    else if ( v4 )
    {
      CSurface::`scalar deleting destructor'(v4, 1);
    }
    if ( v13[0] >= 0 )
    {
      v5 = g_pScoreManagerSurface;
      v13[0] = CScoreManager::InitSurface(*((CScoreManager **)this + 2477));
      if ( v13[0] < 0 )
      {
        g_pScoreManagerSurface = v5;
      }
      else if ( v5 )
      {
        CSurface::`scalar deleting destructor'(v5, 1);
      }
      if ( v13[0] >= 0 )
      {
        v6 = g_pTileManagerSurface;
        v13[0] = CTileManager::InitSurface(*((CTileManager **)this + 2478));
        if ( v13[0] < 0 )
        {
          g_pTileManagerSurface = v6;
        }
        else if ( v6 )
        {
          CSurface::`scalar deleting destructor'(v6, 1);
        }
        if ( v13[0] >= 0 )
        {
          v7 = g_pTimeManagerSurface;
          v13[0] = CTimeManager::InitSurface(*((CTimeManager **)this + 2479));
          if ( v13[0] < 0 )
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
  v8 = v13[0];
  v14 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v10)->~CLogBlock();
  return v8;
}

#endif
