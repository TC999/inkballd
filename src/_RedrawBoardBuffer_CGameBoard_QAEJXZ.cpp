#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int CGameBoard::RedrawBoardBuffer(CGameBoard *this)
{
  int v2; // edi
  bool v3; // cc
  int v4; // eax
  int i; // ebx
  CBoardTile*TileByIndices; // eax
  int v7; // eax
  uint8_t v9[8]; // [esp+10h] [ebp-1Ch] BYREF
  int v10; // [esp+18h] [ebp-14h]
  int v11[3]; // [esp+1Ch] [ebp-10h] BYREF
  int v12; // [esp+28h] [ebp-4h]

  v2 = 0;
  v11[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v9), "CGameBoard::RedrawBoardBuffer", v11);
  v3 = *((uint32_t *)this + 2470) <= 0;
  v12 = 0;
  v10 = 0;
  if ( !v3 )
  {
    v4 = *((uint32_t *)this + 2469);
    do
    {
      for ( i = 0; i < v4; ++i )
      {
        TileByIndices = CGameBoard::GetTileByIndices(this, i, v10);
        CGameBoard::SetTile(this, TileByIndices);
        v4 = *((uint32_t *)this + 2469);
      }
      ++v10;
    }
    while ( v10 < *((uint32_t *)this + 2470) );
  }
  v7 = CGameBoard::Shadowize(this, 0, 17, 0, 17);
  v11[0] = v7;
  if ( v7 < 0
    || (v7 = CGameBoard::BltBoardToInk(this, 0, 0), v11[0] = v7, v7 < 0)
    || (CInk::DrawInkToSurface(*((CInk **)this + 2481), 0), v7 = CDisplay::BltInk(g_pDisplay, 0), v11[0] = v7, v7 < 0) )
  {
    v2 = v7;
  }
  else
  {
    v11[0] = 0;
  }
  v12 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v9)->~CLogBlock();
  return v2;
}
