#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall AddRLColoredWallToList(CBoardTileRLColored*a1)
{
  uint8_t v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "AddRLColoredWallToList", 0);
  v2 = 0;
  CGameBoard::AddRLColoredWallToList(g_pCGameBoard, a1);
  v2 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
