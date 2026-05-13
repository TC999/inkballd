#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
HRSRC __stdcall FindResourceW_Helpers(Helpers* self, HMODULE hModule,
        const WCHAR *lpName,
        LPCWSTR lpType,
        uint16_t *a4,
        int*a5)
{
  HRSRC ResourceW; // esi
  signed int LastError; // eax
  const char*v8[2]; // [esp+4h] [ebp-Ch] BYREF
  char v9[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v9 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v8), "Helpers::FindResourceW", 0);
  ResourceW = ::FindResourceW(hModule, lpName, lpType);
  if ( !ResourceW )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v9 = LastError;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0x67u, &stru_10036F8, v9[0]);
  }
  if ( a4 )
    *(uint32_t *)a4 = *(uint32_t *)v9;
  reinterpret_cast<Helpers::CLogBlock*>(v8)->~CLogBlock();
  return ResourceW;
}
