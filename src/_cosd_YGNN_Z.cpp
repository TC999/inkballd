#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
long double __stdcall cosd(double a1)
{
  uint8_t v2[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "cosd", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return cos(a1 * 0.01745327777777778);
}
