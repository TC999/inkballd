#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall CheckForBallCollisionWithInk(CBall*a1)
{
  int v1; // ebx
  int v2; // esi
  uint8_t v5[8]; // [esp+10h] [ebp-1Ch] BYREF
  int v7; // [esp+28h] [ebp-4h]

  v1 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CheckForBallCollisionWithInk", 0);
  v7 = 0;
  CBoardObject::GetCenterPoint(a1, &v6);
  v2 = *((uint32_t *)a1 + 6) / 2;
  if ( CInk::HitCircleTest(*((CInk **)g_pCGameBoard + 2481), &v6, v2, 0) && CBall::Collide(a1, InkHitTest) )
  {
    CInk::HitCircleTest(*((CInk **)g_pCGameBoard + 2481), &v6, v2, 1);
    CDisplay::BltInk(g_pDisplay, 0);
    PlayingAreaRect = CGameBoard::GetPlayingAreaRect(g_pCGameBoard);
    AddDisplayUpdateRect(PlayingAreaRect);
    v1 = 1;
  }
  v7 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return v1;
}

#endif
