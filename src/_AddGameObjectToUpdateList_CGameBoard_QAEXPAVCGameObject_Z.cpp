#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CGameBoard::AddGameObjectToUpdateList(CGameBoard *this, CGameObject*a2)
{
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::AddGameObjectToUpdateList", 0);
  if ( *(int*)this < 300 )
    *((uint32_t *)this + ++*(uint32_t *)this) = a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
