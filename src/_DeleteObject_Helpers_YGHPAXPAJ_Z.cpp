#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
BOOL __stdcall DeleteObject_Helpers(void* self, HGDIOBJ ho, uint32_t *a2, int*a3)
{
  BOOL v3; // esi
  signed int LastError; // eax
  const char*v6[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v7 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v6), "Helpers::DeleteObject", 0);
  v3 = ::DeleteObject(ho);
  if ( !v3 )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v7 = LastError;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0xEu, &stru_10036F8, v7[0]);
  }
  if ( a2 )
    *a2 = *(uint32_t *)v7;
  reinterpret_cast<Helpers::CLogBlock*>(v6)->~CLogBlock();
  return v3;
}
