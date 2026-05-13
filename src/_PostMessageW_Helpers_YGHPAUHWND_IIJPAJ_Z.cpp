#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
BOOL __stdcall PostMessageW_wpp_Helpers(Helpers* self, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, uint32_t *a5, int*a6)
{
  BOOL v6; // esi
  signed int LastError; // eax
  const char*v9[2]; // [esp+4h] [ebp-Ch] BYREF
  char v10[4]; // [esp+Ch] [ebp-4h] BYREF

  *(uint32_t *)v10 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v9), "Helpers::PostMessageW", 0);
  v6 = ::PostMessageW(hWnd, Msg, wParam, lParam);
  if ( !v6 )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (uint16_t)LastError | 0x80070000;
    *(uint32_t *)v10 = LastError;
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0x37u, &stru_10036F8, v10[0]);
  }
  if ( a5 )
    *a5 = *(uint32_t *)v10;
  reinterpret_cast<Helpers::CLogBlock*>(v9)->~CLogBlock();
  return v6;
}
