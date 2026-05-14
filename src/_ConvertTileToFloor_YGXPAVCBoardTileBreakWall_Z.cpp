#include "global_types.h"
#include <new>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void ConvertTileToFloor(CBoardTileBreakWall*a1)
{
  CBoardTile*v2; // eax
  char*BitmapRect; // eax
  CBoardObject *v4; // eax
  CBoardTile*v5; // ebx
  uint8_t v6[20]; // [esp+10h] [ebp-18h] BYREF
  int v7; // [esp+24h] [ebp-4h]
  CBoardObject *v8; // [esp+30h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "ConvertTileToFloor", 0);
  v2 = (CBoardTile*)*((uint32_t *)a1 + 22);
  v7 = 0;
  if ( v2 )
  {
    v5 = v2;
    goto LABEL_8;
  }
  LOBYTE(v7) = 1;
  v8 = (CBoardObject *)operator new(0x58u);
  LOBYTE(v7) = 2;
  if ( v8 )
  {
    BitmapRect = CGameBoard::GetBitmapRect(0);
    v4 = new (v8) CBoardTile(0, *((uint32_t *)a1 + 19), *((uint32_t *)a1 + 20), (int)BitmapRect);
  }
  else
  {
    v4 = 0;
  }
  v5 = v4;
  v7 = 0;
  if ( v4 )
  {
    *((uint32_t *)v4 + 6) = *((uint32_t *)g_pCGameBoard + 2472);
    *((uint32_t *)v4 + 7) = *((uint32_t *)g_pCGameBoard + 2472);
    *((double *)v4 + 1) = *((double *)a1 + 1);
    *((double *)v4 + 2) = *((double *)a1 + 2);
LABEL_8:
    operator delete(a1);
    CGameBoard::SetTile(g_pCGameBoard, v5);
    CGameBoard::ShadowizeTile((CInk **)g_pCGameBoard, v5, 0);
  }
  v7 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v6)->~CLogBlock();
}
