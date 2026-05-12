#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
LSTATUS __stdcall Helpers::RegCloseKey(HKEY hKey, HKEY a2, int*a3)
{
  LSTATUS v3; // eax
  LSTATUS v4; // esi
  int v5; // ecx
  const char*v7[2]; // [esp+4h] [ebp-Ch] BYREF
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v8 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v7), "Helpers::RegCloseKey", 0);
  v3 = ::RegCloseKey(hKey);
  v4 = v3;
  if ( v3 )
  {
    v5 = v3;
    if ( v3 > 0 )
      v5 = (uint16_t)v3 | 0x80070000;
    v8 = v5;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0x3Au, &stru_10036F8, v5);
  }
  v5 = v8;
  if ( a2 )
    *(uint32_t *)a2 = v5;
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
  return v4;
}
