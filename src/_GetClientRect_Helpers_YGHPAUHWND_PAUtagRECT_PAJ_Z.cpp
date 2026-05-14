#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
BOOL __stdcall GetClientRect_Helpers(void* self, HWND hWnd, RECT *lpRect, RECT *a3, int*a4)
{
  BOOL ClientRect; // esi
  signed int LastError; // eax
  const char*v7[2]; // [esp+4h] [ebp-Ch] BYREF
  char v8[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v8 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v7), "Helpers::GetClientRect", 0);
  ClientRect = ::GetClientRect(hWnd, lpRect);
  if ( !ClientRect )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v8 = LastError;
    if ( (uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && (*((uint8_t*)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*(uint64_t*)((uint8_t*)WPP_GLOBAL_Control + 2*8), 0x1Du, &stru_10036F8, v8[0]);
  }
  if ( a3 )
    a3->left = *(uint32_t *)v8;
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
  return ClientRect;
}
