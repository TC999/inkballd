#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
LSTATUS __stdcall RegSetValueExW_Helpers(Helpers* self, HKEY hKey,
        const WCHAR *lpValueName,
        DWORD Reserved,
        DWORD dwType,
        BYTE *lpData,
        DWORD cbData,
        int*a7,
        int*a8)
{
  LSTATUS v8; // eax
  LSTATUS v9; // esi
  int v10; // ecx
  const char*v12[2]; // [esp+4h] [ebp-Ch] BYREF
  int v13; // [esp+Ch] [ebp-4h] BYREF

  v13 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v12), "Helpers::RegSetValueExW", 0);
  v8 = ::RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData);
  v9 = v8;
  if ( v8 )
  {
    v10 = v8;
    if ( v8 > 0 )
      v10 = (uint16_t)v8 | 0x80070000;
    v13 = v10;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0x3Du, &stru_10036F8, v10);
  }
  v10 = v13;
  if ( a7 )
    *a7 = v10;
  reinterpret_cast<Helpers::CLogBlock*>(v12)->~CLogBlock();
  return v9;
}
