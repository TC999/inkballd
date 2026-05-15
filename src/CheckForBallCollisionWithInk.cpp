// [COMPLEX] Undeclared CInk::HitCircleTest, undeclared locals (v6, InkHitTest, PlayingAreaRect, AddDisplayUpdateRect) — left wrapped
#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int __stdcall CheckForBallCollisionWithInk(CBall* a1)
{
  int v1;
  int v2;
  uint8_t v5[8];
  int v7;

  v1 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "CheckForBallCollisionWithInk", 0);
  v7 = 0;
  CBoardObject::GetCenterPoint(a1, &v6);
  v2 = *((uint32_t *)a1 + 6) / 2;
  if ( CInk_HitCircleTest(*((CInk **)g_pCGameBoard + 2481), &v6, v2, 0) && CBall::Collide(a1, InkHitTest) )
  {
    CInk_HitCircleTest(*((CInk **)g_pCGameBoard + 2481), &v6, v2, 1);
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
