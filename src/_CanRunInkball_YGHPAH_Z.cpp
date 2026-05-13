// [COMPLEX] Undeclared TabUtils::TabQueryPolicyValue — left wrapped
#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int __stdcall CanRunInkball(int* a1)
{
  int v1;
  int* v3;
  uint8_t v4[8];
  int v5[3];
  int v6;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CanRunInkball", 0);
  v6 = 0;
  v1 = CTabLicense_CanRunInkball();
  if ( v1 )
  {
    v5[0] = 0;
    if ( TabUtils::TabQueryPolicyValue(L"DisableInkball", 0, (int)v5, 0, v3) >= 0 && v5[0] )
      v1 = 0;
    if ( a1 )
      *a1 = 0;
  }
  else if ( a1 )
  {
    *a1 = 1;
  }
  v6 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v1;
}

#endif
