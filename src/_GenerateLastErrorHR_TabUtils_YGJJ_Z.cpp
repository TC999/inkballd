#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
TabUtils *__stdcall TabUtils::GenerateLastErrorHR(TabUtils *this, int a2)
{
  TabUtils *result; // eax
  bool v3; // sf

  result = (TabUtils *)GetLastError();
  v3 = (int)result < 0;
  if ( (int)result > 0 )
  {
    result = (TabUtils *)((uint16_t)result | 0x80070000);
    v3 = (int)result < 0;
  }
  if ( !v3 )
    return this;
  return result;
}

#endif
