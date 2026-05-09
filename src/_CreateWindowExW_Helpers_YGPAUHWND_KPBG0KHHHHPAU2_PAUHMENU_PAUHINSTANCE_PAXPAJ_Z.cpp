#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
HWND __stdcall Helpers::CreateWindowExW(
        DWORD dwExStyle,
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
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "Helpers::CreateWindowExW", (int*)v18);
  v19 = 0;
  Window = CreateWindowExW(
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
    *(uint32_t *)v18 = TabUtils::GenerateLastErrorHR((TabUtils *)0x80004005, v16);
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x60u, &stru_10036F8, v18[0]);
  }
  if ( a13 )
    *a13 = *(uint32_t *)v18;
  Helpers::CLogBlock::~CLogBlock(v17);
  return Window;
}
