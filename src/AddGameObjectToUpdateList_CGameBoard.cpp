#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CGameBoard::AddGameObjectToUpdateList(CGameBoard *self, CGameObject* a2)
{
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CGameBoard::AddGameObjectToUpdateList", 0);
  if ( *(int*)self < 300 )
    *((uint32_t *)self + ++*(uint32_t *)self) = (uint32_t)a2;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
