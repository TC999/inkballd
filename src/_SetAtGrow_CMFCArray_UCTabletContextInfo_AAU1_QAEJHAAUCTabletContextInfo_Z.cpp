#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetAtGrow(uint32_t *this, int a2, const void*a3)
{
  int result; // eax

  result = 0;
  if ( a2 < 0 )
    return -2147024809;
  if ( a2 < this[1]
    || (result = CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetSize((int)this, a2 + 1, -1), result >= 0) )
  {
    qmemcpy((void*)(*this + 24 * a2), a3, 0x18u);
  }
  return result;
}
