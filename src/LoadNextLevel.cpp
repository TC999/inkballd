#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void __stdcall LoadNextLevel()
{
  int v0; // edx
  uint8_t v1[8]; // [esp+10h] [ebp-18h] BYREF
  int v2[3]; // [esp+18h] [ebp-10h] BYREF
  int v3; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v1), "LoadNextLevel", 0);
  v0 = *((uint32_t *)g_pCGameManager + 3) % 5;
  v3 = 0;
  if ( v0 )
    ((CBoardManager*)g_CBoardManager)->LoadRandomBoardFromResources((unsigned char*)&g_BoardData, v2);
  else
    ((CBoardManager*)g_CBoardManager)->LoadRandomBonusBoardFromResources((unsigned char*)&g_BoardData, v2);
  CGameManager::LoadBoard((CGameManager*)g_pCGameManager, &g_BoardData, v2[0]);
  v3 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}
