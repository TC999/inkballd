#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <new>

void CBall::SetYVel(CBall *self, long double a2)
{
  long double v3;
  uint8_t v4[8];

  new (v4) Helpers::CLogBlock(v4, "CBall::SetYVel", 0);
  if ( fabs(a2) > 400.0 )
    v3 = 400.0 * (*((double *)self + 9) / fabs(*((double *)self + 9)));
  else
    v3 = a2;
  *((long double *)self + 9) = v3;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
