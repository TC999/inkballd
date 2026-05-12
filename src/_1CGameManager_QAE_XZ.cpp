#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void CGameManager_Dtor_impl(CGameManager *this_ptr)
{
  uint8_t v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "CGameManager::~CGameManager", 0);
  v2 = 0;
  if ( g_pCGameBoard )
  {
    CGameBoard_Dtor(g_pCGameBoard, 1);
    g_pCGameBoard = 0;
  }
  v2 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}
