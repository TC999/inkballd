#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
BOOL __stdcall CloseHandle_wpp_Helpers(void* self, HANDLE hObject, uint32_t *a2, int*a3)
{
  BOOL v3; // esi
  signed int LastError; // eax
  const char*v6[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v7 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v6), "Helpers::CloseHandle", 0);
  v3 = ::CloseHandle(hObject);
  if ( !v3 )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v7 = LastError;
    if ( (uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && (*((uint8_t*)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*(uint64_t*)((uint8_t*)WPP_GLOBAL_Control + 2*8), 0x46u, &stru_10036F8, v7[0]);
  }
  if ( a2 )
    *a2 = *(uint32_t *)v7;
  reinterpret_cast<Helpers::CLogBlock*>(v6)->~CLogBlock();
  return v3;
}
