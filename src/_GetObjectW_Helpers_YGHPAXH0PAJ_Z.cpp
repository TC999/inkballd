#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int __stdcall GetObjectW_Helpers(Helpers* self, HANDLE h, void*c, LPVOID pv, uint32_t *a4, int*a5)
{
  int ObjectW; // esi
  signed int LastError; // eax
  const char*v8[2]; // [esp+4h] [ebp-Ch] BYREF
  char v9[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "Helpers::GetObjectW", (int*)v9);
  SetLastError(0);
  ObjectW = GetObjectW(h, (int)c, pv);
  LastError = GetLastError();
  if ( LastError > 0 )
    LastError = (uint16_t)LastError | 0x80070000;
  *(uint32_t *)v9 = LastError;
  if ( LastError < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x12u, &stru_10036F8, v9[0]);
  if ( a4 )
    *a4 = *(uint32_t *)v9;
  ((Helpers::CLogBlock*)v8)->~CLogBlock();
  return ObjectW;
}

