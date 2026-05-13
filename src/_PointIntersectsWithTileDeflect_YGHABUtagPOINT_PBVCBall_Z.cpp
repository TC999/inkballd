#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
BOOL __stdcall PointIntersectsWithTileDeflect(const struct tagPOINT *a1, const CBall*a2)
{
  BOOL v2; // eax
  BOOL v3; // esi
  uint8_t v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "PointIntersectsWithTileDeflect", 0);
  v6 = 0;
  v2 = CGameBoard::PointIntersectsWithTile(g_pCGameBoard, a1, a2, 1);
  v6 = -1;
  v3 = v2;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return v3;
}
