#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall LoadNextLevel()
{
  int v0; // edx
  uint8_t v1[8]; // [esp+10h] [ebp-18h] BYREF
  int v2[3]; // [esp+18h] [ebp-10h] BYREF
  int v3; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "LoadNextLevel", 0);
  v0 = *((uint32_t *)g_pCGameManager + 3) % 5;
  v3 = 0;
  if ( v0 )
    CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &Src, v2);
  else
    CBoardManager::LoadRandomBonusBoardFromResources((CBoardManager *)&g_CBoardManager, &Src, v2);
  CGameManager::LoadBoard(g_pCGameManager, &Src, v2[0]);
  v3 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}

#endif
