#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall RtlpImageNtHeader(int a1)
{
  int result; // eax
  uint32_t v2; // edx

  result = 0;
  if ( a1 )
  {
    if ( a1 != -1 && *(uint16_t *)a1 == 23117 )
    {
      v2 = *(uint32_t *)(a1 + 60);
      if ( v2 < 0x10000000 )
      {
        result = v2 + a1;
        if ( *(uint32_t *)(v2 + a1) != 17744 )
          return 0;
      }
    }
  }
  return result;
}
