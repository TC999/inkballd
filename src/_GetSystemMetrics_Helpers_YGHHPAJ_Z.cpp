#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall Helpers::GetSystemMetrics(Helpers *this, int*a2, int*a3)
{
  int SystemMetrics; // esi
  const char*v5[2]; // [esp+4h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v6 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "Helpers::GetSystemMetrics", &v6);
  SystemMetrics = GetSystemMetrics((int)this);
  if ( !SystemMetrics )
  {
    v6 = -2147467259;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x33u, &stru_10036F8, 5);
  }
  if ( a2 )
    *a2 = v6;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return SystemMetrics;
}

#endif
