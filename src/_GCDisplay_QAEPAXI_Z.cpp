#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
CDisplay *__thiscall CDisplay::`scalar deleting destructor'(CDisplay *this, char a2)
{
  CDisplay::~CDisplay(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}

#endif
