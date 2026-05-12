#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int __stdcall Helpers::GetSystemMetrics(void* self, int*a2, int*a3)
{
  int SystemMetrics; // esi
  const char*v5[2]; // [esp+4h] [ebp-Ch] BYREF
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v6 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "Helpers::GetSystemMetrics", 0);
  SystemMetrics = ::GetSystemMetrics(reinterpret_cast<int>(self));
  if ( !SystemMetrics )
  {
    v6 = -2147467259;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0x33u, &stru_10036F8, 5);
  }
  if ( a2 )
    *a2 = v6;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return SystemMetrics;
}
