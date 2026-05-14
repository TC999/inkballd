#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void Paint_CGameBoard(CGameBoard *self)
{
    void* DirectDraw;
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)v3, "CGameBoard::Paint", 0);
  v4 = 0;
  DirectDraw = CDisplay::GetDirectDraw(g_pDisplay);
  if ( ((IDirectDraw7*)DirectDraw)->lpVtbl->TestCooperativeLevel(((IDirectDraw7*)DirectDraw)) == -2005532085 )
  {
    CGameBoard::CreateNewSurfaces(self);
    CGameBoard::RestoreSurfaces(self);
  }
  if ( CGameBoard::DisplayFrame(self, 1, 1) == -2005532222 )
  {
    CGameBoard::RestoreSurfaces(self);
    CGameBoard::DisplayFrame(self, 1, 1);
  }
  v4 = -1;
  ((Helpers::CLogBlock*)v3)->~CLogBlock();
}

