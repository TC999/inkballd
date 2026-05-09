#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CGameManager::~CGameManager(CGameManager *this)
{
  uint8_t v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "CGameManager::~CGameManager", 0);
  v2 = 0;
  if ( g_pCGameBoard )
  {
    CGameBoard::`scalar deleting destructor'(g_pCGameBoard, 1);
    g_pCGameBoard = 0;
  }
  v2 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
