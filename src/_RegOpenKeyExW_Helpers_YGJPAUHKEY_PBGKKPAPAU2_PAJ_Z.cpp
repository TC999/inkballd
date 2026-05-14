#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
LSTATUS __stdcall RegOpenKeyExW_Helpers(void* self, HKEY hKey,
        const WCHAR *lpSubKey,
        DWORD ulOptions,
        REGSAM samDesired,
        PHKEY phkResult,
        HKEY *a6,
        int*a7)
{
  LSTATUS v7; // eax
  LSTATUS v8; // esi
  HKEY v9; // ecx
  const char*v11[2]; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-4h] BYREF

  v12 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v11), "Helpers::RegOpenKeyExW", 0);
  v7 = ::RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult);
  v8 = v7;
  if ( v7 )
  {
    v9 = (HKEY)v7;
    if ( v7 > 0 )
      v9 = (HKEY)((uint16_t)v7 | 0x80070000);
    v12 = (int)v9;
    if ( (uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && (*((uint8_t*)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*(uint64_t*)((uint8_t*)WPP_GLOBAL_Control + 2*8), 0x39u, &stru_10036F8, (char)v9);
  }
  v9 = (HKEY)v12;
  if ( a6 )
    *a6 = v9;
  reinterpret_cast<Helpers::CLogBlock*>(v11)->~CLogBlock();
  return v8;
}
