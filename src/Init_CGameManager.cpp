#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int CGameManager_Init_impl(CGameManager *this_ptr)
{
  int v1; // eax
  int v2; // esi
  uint8_t v4[8]; // [esp+10h] [ebp-18h] BYREF
  int v5[3]; // [esp+18h] [ebp-10h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  v5[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameManager::Init", (int)v5);
  v6 = 0;
  v1 = CGameBoard_Init(g_pCGameBoard);
  v6 = -1;
  v5[0] = v1;
  v2 = v1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}
