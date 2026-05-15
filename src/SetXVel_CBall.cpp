#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <new>
void SetXVel_CBall(CBall* self, long double a2)
{
  long double v3; // st7
  uint8_t v4[8]; // [esp+4h] [ebp-8h] BYREF

  new (v4) Helpers::CLogBlock(v4, "CBall::SetXVel", 0);
  if ( fabs(a2) > 400.0 )
    v3 = 400.0 * (*((double *)self + 8) / fabs(*((double *)self + 8)));
  else
    v3 = a2;
  *((long double *)self + 8) = v3;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
