#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
HWND __stdcall CreateWindowExW_Helpers(void* self, DWORD dwExStyle,
        LPCWSTR lpClassName,
        LPCWSTR lpWindowName,
        DWORD dwStyle,
        uint32_t X,
        int Y,
        int nWidth,
        int nHeight,
        HWND hWndParent,
        HMENU hMenu,
        HINSTANCE hInstance,
        HINSTANCE lpParam,
        uint32_t *a13,
        int*a14)
{
  HWND Window; // esi
  int v16; // [esp+0h] [ebp-28h]
  const char*v17[2]; // [esp+10h] [ebp-18h] BYREF
  char v18[4]; // [esp+18h] [ebp-10h] BYREF
  int v19; // [esp+24h] [ebp-4h]

  *(uint32_t *)v18 = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v17), "Helpers::CreateWindowExW", 0);
  v19 = 0;
  Window = ::CreateWindowExW(
             dwExStyle,
             lpClassName,
             lpWindowName,
             dwStyle,
             X,
             Y,
             nWidth,
             nHeight,
             hWndParent,
             hMenu,
             hInstance,
             lpParam);
  if ( !Window )
  {
    *(uint32_t *)v18 = TabUtils::GenerateLastErrorHR(0x80004005, v16);
    if ( WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[28] & 4) != 0 )
      WPP_SF_d(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0x60u, &stru_10036F8, v18[0]);
  }
  if ( a13 )
    *a13 = *(uint32_t *)v18;
  reinterpret_cast<Helpers::CLogBlock*>(v17)->~CLogBlock();
  return Window;
}
