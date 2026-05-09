#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall ScoreBall(CBall *a1, int a2)
{
  int*DrainPoints; // eax
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "ScoreBall", 0);
  v4 = 0;
  if ( a2 )
  {
    DrainPoints = CBall::GetDrainPoints(a1);
    CScoreManager::IncrementScore(*((CScoreManager **)g_pCGameBoard + 2477), (int)DrainPoints);
  }
  if ( (int)--*((uint32_t *)g_pCGameBoard + 2473) <= 0 )
    *((uint32_t *)g_pCGameManager + 4) = 2;
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
