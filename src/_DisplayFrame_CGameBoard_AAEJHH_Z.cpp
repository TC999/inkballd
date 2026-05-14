#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int DisplayFrame_CGameBoard(CGameBoard* self, int a2, int a3)
{
    void* BackBuffer;
    RECT* PlayingAreaRect;
    RECT v12;
    RECT v13;
  int v4;
  int v6;
  uint32_t *v8;
  bool v10;
  uint8_t v14[8];
  uint32_t *v15;
  char*v16;
  int v17[3];
  int v18;
  int v19;
  int v20;

  v4 = 0;
  v17[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v14), "CGameBoard::DisplayFrame", v17);
  v18 = 0;
  if ( !BoardIsActive() && !a3 )
    goto LABEL_25;
  CDisplay::Blt(
    g_pDisplay,
    *(uint32_t *)(*((uint32_t *)self + 2476) + 4),
    *(uint32_t *)(*((uint32_t *)self + 2476) + 8),
    g_pBallManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(uint32_t *)(*((uint32_t *)self + 2477) + 4),
    *(uint32_t *)(*((uint32_t *)self + 2477) + 8),
    g_pScoreManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(uint32_t *)(*((uint32_t *)self + 2478) + 4),
    *(uint32_t *)(*((uint32_t *)self + 2478) + 8),
    g_pTileManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(uint32_t *)(*((uint32_t *)self + 2479) + 4),
    *(uint32_t *)(*((uint32_t *)self + 2479) + 8),
    g_pTimeManagerSurface,
    0);
  (CInk::GetInkUpdateRect(*((CInk**)self + 2481), &v12));
    CGameBoard::AddDisplayUpdateRect(self, &v12);
  PlayingAreaRect = CGameBoard::GetPlayingAreaRect(self);
  v6 = CDisplay::BltInk(g_pDisplay, PlayingAreaRect);
  v17[0] = v6;
  if ( v6 < 0 )
    goto LABEL_6;
  v19 = 0;
  if ( *((int*)self + 656) > 0 )
  {
    v16 = reinterpret_cast<char*>(self) + 2628;
    while ( 1 )
    {
      v8 = *(uint32_t **)v16;
      if ( *(uint32_t *)(*(uint32_t *)v16 + 156) )
        break;
      v10 = v8[40] == 0;
      v15 = v8 + 40;
      if ( !v10 )
      {
        CMovingObject::GetMovementRect((CMovingObject *)v8, &v13);
        *v15 = 0;
LABEL_16:
        CGameBoard::AddDisplayUpdateRect(self, &v13);
      }
LABEL_17:
      ++v19;
      v16 += 4;
      if ( v19 >= *((uint32_t *)self + 656) )
        goto LABEL_18;
    }
    BackBuffer = CDisplay::GetBackBuffer(g_pDisplay);
    v6 = CGameBoard::BltBall(self, (CBall*)v8, (IDirectDrawSurface7*)BackBuffer);
    v17[0] = v6;
    if ( v6 < 0 )
      goto LABEL_6;
    if ( a2 )
      goto LABEL_17;
    CMovingObject::GetMovementRect((CMovingObject *)v8, &v13);
    goto LABEL_16;
  }
LABEL_18:
  if ( !a2 )
  {
    v20 = 0;
    if ( *((int*)self + 1018) > 0 )
    {
      RECT* update_rects = (RECT*)(reinterpret_cast<char*>(self) + 4076);
      do
      {
        v6 = CDisplay::Present(g_pDisplay, &update_rects[v20]);
        v17[0] = v6;
        if ( v6 < 0 )
          goto LABEL_6;
        ++v20;
      }
      while ( v20 < *((uint32_t *)self + 1018) );
    }
LABEL_25:
    v17[0] = 0;
    goto LABEL_7;
  }
  v6 = CDisplay::Present(g_pDisplay, 0);
  v17[0] = v6;
  if ( v6 >= 0 )
    goto LABEL_25;
LABEL_6:
  v4 = v6;
LABEL_7:
  v18 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v14)->~CLogBlock();
  return v4;
}
