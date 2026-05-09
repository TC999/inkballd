#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CGameBoard::ShadowizeTile(CInk **this, CBoardTile*a2, int a3)
{
  int v4; // edi
  int v5; // eax
  uint8_t v8[8]; // [esp+20h] [ebp-18h] BYREF
  int v9[3]; // [esp+28h] [ebp-10h] BYREF
  int v10; // [esp+34h] [ebp-4h]

  v4 = 0;
  v9[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CGameBoard::ShadowizeTile", v9);
  v10 = 0;
  CBoardObject::GetBoundingRect(a2, &v7);
  v5 = CGameBoard::BltBoardToInk((CGameBoard *)this, &v7, 1);
  v9[0] = v5;
  if ( v5 >= 0 )
  {
    CGameBoard::AddDisplayUpdateRect((CGameBoard *)this, &v7);
    CInk::SetInkRedrawFlag(this[2481]);
    v9[0] = 0;
  }
  else
  {
    v4 = v5;
  }
  v10 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v4;
}
