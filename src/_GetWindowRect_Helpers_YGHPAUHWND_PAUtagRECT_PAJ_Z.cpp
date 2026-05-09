#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
BOOL __stdcall Helpers::GetWindowRect(HWND hWnd, struct tagRECT *lpRect, struct tagRECT *a3, int*a4)
{
  BOOL WindowRect; // esi
  signed int LastError; // eax
  const char*v7[2]; // [esp+4h] [ebp-Ch] BYREF
  char v8[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v8 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "Helpers::GetWindowRect", (int*)v8);
  WindowRect = GetWindowRect(hWnd, lpRect);
  if ( !WindowRect )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v8 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x21u, &stru_10036F8, v8[0]);
  }
  if ( a3 )
    a3->left = *(uint32_t *)v8;
  Helpers::CLogBlock::~CLogBlock(v7);
  return WindowRect;
}
