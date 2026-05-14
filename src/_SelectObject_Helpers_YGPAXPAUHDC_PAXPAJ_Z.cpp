#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
HGDIOBJ __stdcall SelectObject_Helpers(void* self, HDC hdc, HGDIOBJ h, uint32_t *a3, int*a4)
{
  HGDIOBJ v4; // esi
  signed int LastError; // eax
  const char*v7[2]; // [esp+4h] [ebp-Ch] BYREF
  char v8[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v8 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v7), "Helpers::SelectObject", 0);
  v4 = ::SelectObject(hdc, h);
  if ( !v4 )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v8 = LastError;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0xDu, &stru_10036F8, v8[0]);
  }
  if ( a3 )
    *a3 = *(uint32_t *)v8;
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
  return v4;
}
