#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
HANDLE __stdcall Helpers::LoadImageW(
        HINSTANCE hInst,
        const WCHAR *name,
        UINT type,
        uint32_t a4,
        int cy,
        UINT fuLoad,
        uint32_t *a7,
        int*a8)
{
  HANDLE ImageW; // esi
  signed int LastError; // eax
  const char*v11[2]; // [esp+4h] [ebp-Ch] BYREF
  char v12[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "Helpers::LoadImageW", (int*)v12);
  ImageW = LoadImageW(hInst, name, type, a4, cy, fuLoad);
  if ( !ImageW )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v12 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x2Du, &stru_10036F8, v12[0]);
  }
  if ( a7 )
    *a7 = *(uint32_t *)v12;
  reinterpret_cast<Helpers::CLogBlock*>(v11)->~CLogBlock();
  return ImageW;
}

#endif
