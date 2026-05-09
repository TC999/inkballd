#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CGameBoard::Paint(CGameBoard *this)
{
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::Paint", 0);
  v4 = 0;
  DirectDraw = CDisplay::GetDirectDraw(g_pDisplay);
  if ( DirectDraw->lpVtbl->TestCooperativeLevel(DirectDraw) == -2005532085 )
  {
    CGameBoard::CreateNewSurfaces(this);
    CGameBoard::RestoreSurfaces((CScoreManager **)this);
  }
  if ( CGameBoard::DisplayFrame(this, 1, 1) == -2005532222 )
  {
    CGameBoard::RestoreSurfaces((CScoreManager **)this);
    CGameBoard::DisplayFrame(this, 1, 1);
  }
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
