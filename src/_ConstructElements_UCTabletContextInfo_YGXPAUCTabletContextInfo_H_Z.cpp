#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

uint32_t ConstructElements_CTabletContextInfo(uint32_t *a1, uint32_t a2)
{
  uint32_t v2; // ebx
  uint32_t result; // eax
  uint32_t *v4; // esi

  v2 = a2;
  result = 24 * a2;
  if ( is_mul_ok(0x18u, a2) && result != -1 )
  {
    v4 = a1;
    result = (uint32_t)memset(a1, 0, 24 * a2);
    while ( v2 )
    {
      --v2;
      if ( v4 )
      {
        *v4 = 0;
        v4[1] = 0;
        v4[2] = 0;
        v4[3] = 0;
        v4[4] = 0;
        v4[5] = 0;
      }
      v4 += 6;
    }
  }
  return result;
}
