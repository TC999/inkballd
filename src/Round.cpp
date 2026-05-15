#include <cmath>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "global_types.h"

uint32_t __stdcall Round(double X)
{
  double v1;
  double Y;
  uint8_t v4[16];
  int v5;

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "Round", 0);
  if ( modf(X, &Y) < 0.5 )
    v1 = floor(X);
  else
    v1 = ceil(X);
  v5 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return (uint32_t)v1;
}
