#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CScoreManager *__thiscall CScoreManager::`scalar deleting destructor'(CScoreManager *this, char a2)
{
  CScoreManager::~CScoreManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

#endif
