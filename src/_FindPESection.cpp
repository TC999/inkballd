#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"

int __cdecl _FindPESection(int a1, uint32_t a2)
{
  int v2; // ecx
  uint32_t v3; // esi
  uint32_t v4; // edx
  int result; // eax
  uint32_t v6; // ecx

  v2 = a1 + *reinterpret_cast<uint32_t*>(a1 + 60);
  v3 = *reinterpret_cast<uint16_t*>(v2 + 6);
  v4 = 0;
  result = *reinterpret_cast<uint16_t*>(v2 + 20) + v2 + 24;
  if ( !*reinterpret_cast<uint16_t*>(v2 + 6) )
    return 0;
  while ( 1 )
  {
    v6 = *reinterpret_cast<uint32_t*>(result + 12);
    if ( a2 >= v6 && a2 < v6 + *reinterpret_cast<uint32_t*>(result + 8) )
      break;
    ++v4;
    result += 40;
    if ( v4 >= v3 )
      return 0;
  }
  return result;
}
