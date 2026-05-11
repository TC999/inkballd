#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall ScoreBreak(CBall*a1)
{
  int*BreakWallPoints; // eax
  uint8_t v2[16]; // [esp+10h] [ebp-14h] BYREF
  int v3; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "ScoreBreak", 0);
  v3 = 0;
  BreakWallPoints = CBall::GetBreakWallPoints(a1);
  CScoreManager::IncrementScore(*((CScoreManager **)g_pCGameBoard + 2477), (int)BreakWallPoints);
  v3 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}

#endif
