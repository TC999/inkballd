#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int ShadowizeTile_CGameBoard(CGameBoard* self, CBoardTile*a2, int a3)
{
    RECT v7;
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
  v5 = CGameBoard::BltBoardToInk(self, &v7, 1);
  v9[0] = v5;
  if ( v5 >= 0 )
  {
    CGameBoard::AddDisplayUpdateRect(self, &v7);
    CInk::SetInkRedrawFlag(*reinterpret_cast<CInk**>(reinterpret_cast<uint8_t*>(self) + 2481));
    v9[0] = 0;
  }
  else
  {
    v4 = v5;
  }
  v10 = -1;
  ((Helpers::CLogBlock *)v8)->~CLogBlock();
  return v4;
}
