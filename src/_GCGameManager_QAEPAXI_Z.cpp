#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CGameManager *__thiscall CGameManager::`scalar deleting destructor'(CGameManager *this, char a2)
{
  CGameManager::~CGameManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

#endif
