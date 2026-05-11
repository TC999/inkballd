#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall Helpers::LoadStringW(
        HINSTANCE hInstance,
        UINT uID,
        LPWSTR lpBuffer,
        uint16_t *cchBufferMax,
        uint32_t *a5,
        int*a6)
{
  int StringW; // esi
  signed int LastError; // eax
  const char*v9[2]; // [esp+4h] [ebp-Ch] BYREF
  char v10[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v10 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "Helpers::LoadStringW", (int*)v10);
  StringW = LoadStringW(hInstance, uID, lpBuffer, (int)cchBufferMax);
  if ( !StringW )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v10 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x2Eu, &stru_10036F8, v10[0]);
  }
  if ( a5 )
    *a5 = *(uint32_t *)v10;
  reinterpret_cast<Helpers::CLogBlock*>(v9)->~CLogBlock();
  return StringW;
}

#endif
