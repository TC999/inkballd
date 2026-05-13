#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
LSTATUS __stdcall RegCreateKeyExW_Helpers(Helpers* self, HKEY hKey,
        const WCHAR *lpSubKey,
        DWORD Reserved,
        LPWSTR lpClass,
        DWORD dwOptions,
        REGSAM samDesired,
        LPSECURITY_ATTRIBUTES lpSecurityAttributes,
        PHKEY phkResult,
        LPDWORD lpdwDisposition,
        uint32_t *a10,
        int*a11)
{
  LSTATUS Key; // eax
  LSTATUS v12; // esi
  uint32_t v13; // ecx
  const char*v15[2]; // [esp+4h] [ebp-Ch] BYREF
  int v16; // [esp+Ch] [ebp-4h] BYREF

  v16 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v15), "Helpers::RegCreateKeyExW", 0);
  Key = ::RegCreateKeyExW(
          hKey,
          lpSubKey,
          Reserved,
          lpClass,
          dwOptions,
          samDesired,
          lpSecurityAttributes,
          phkResult,
          lpdwDisposition);
  v12 = Key;
  if ( Key )
  {
    v13 = Key;
    if ( Key > 0 )
      v13 = (uint16_t)Key | 0x80070000;
    v16 = v13;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0x3Bu, &stru_10036F8, v13);
  }
  v13 = v16;
  if ( a10 )
    *a10 = v13;
  reinterpret_cast<Helpers::CLogBlock*>(v15)->~CLogBlock();
  return v12;
}
