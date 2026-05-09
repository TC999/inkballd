#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    CInk* CInk::CInk(CInk* this_ptr, HWND window_handle)
    {
      int* unused_ptr; // [esp+0h] [ebp-24h]
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CInk::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CInk::CInk", 0);
      cleanup_flag = 0;
      Helpers::GetClientRect(window_handle, &g_rcClient, 0, unused_ptr);
      cleanup_flag = -1;
      dword_10B0664 = 10 * (dword_10B0674 - g_rcClient.left);
      g_hWnd = window_handle;
      dword_10B0668 = 10 * (dword_10B0678 - dword_10B0670);
      *reinterpret_cast<uint32_t*>(this_ptr + 4) = 0;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
