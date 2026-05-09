#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
uint32_t __stdcall Round(double X)
{
  double v1; // st7
  double Y; // [esp+1Ch] [ebp-1Ch] BYREF
  uint8_t v4[16]; // [esp+24h] [ebp-14h] BYREF
  int v5; // [esp+34h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "Round", 0);
  if ( _modf(X, &Y) < 0.5 )
    v1 = floor(X);
  else
    v1 = _ceil(X);
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return (unsigned int64_t)v1;
}
