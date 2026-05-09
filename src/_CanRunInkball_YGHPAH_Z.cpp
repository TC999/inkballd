#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall CanRunInkball(int*a1)
{
  int v1; // edi
  int*v3; // [esp+0h] [ebp-28h]
  uint8_t v4[8]; // [esp+10h] [ebp-18h] BYREF
  int v5[3]; // [esp+18h] [ebp-10h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CanRunInkball", 0);
  v6 = 0;
  v1 = CTabLicense::CanRunInkball();
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
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v1;
}
