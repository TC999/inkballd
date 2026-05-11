#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CGameBoard *__thiscall CGameBoard::`scalar deleting destructor'(CGameBoard *this, char a2)
{
  CGameBoard::~CGameBoard(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

#endif
