#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    int CDisplay::UpdateBounds(CDisplay* this_ptr)
    {
      bool is_fullscreen; // zf
      uint32_t* width_ptr; // ebx
      int temp_value; // eax
      int* system_metrics; // eax
      int client_height; // eax
      int result; // esi
      int window_height; // [esp-4h] [ebp-2Ch]
      int* unused_ptr; // [esp+0h] [ebp-28h]
      uint8_t log_buffer[8]; // [esp+10h] [ebp-18h] BYREF
      int error_code[3]; // [esp+18h] [ebp-10h] BYREF
      int cleanup_flag; // [esp+24h] [ebp-4h]

      error_code[0] = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CDisplay::UpdateBounds", error_code);
      is_fullscreen = *reinterpret_cast<uint32_t*>(this_ptr + 12) == 0;
      cleanup_flag = 0;
      if (is_fullscreen)
      {
        system_metrics = reinterpret_cast<int*>(Helpers::GetSystemMetrics(reinterpret_cast<Helpers*>(1), 0, unused_ptr));
        client_height = Helpers::GetSystemMetrics(0, 0, system_metrics);
        SetRect(reinterpret_cast<LPRECT>(this_ptr + 2), 0, 0, client_height, window_height);
      }
      else
      {
        Helpers::GetClientRect(*reinterpret_cast<HWND*>(this_ptr + 7), reinterpret_cast<HWND>(this_ptr + 8), 0, unused_ptr);
        ClientToScreen(*reinterpret_cast<HWND*>(this_ptr + 7), reinterpret_cast<LPPOINT>(this_ptr + 4));
        width_ptr = reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(this_ptr) + 40);
        ClientToScreen(*reinterpret_cast<HWND*>(this_ptr + 7), reinterpret_cast<LPPOINT>(this_ptr + 5));
        temp_value = *reinterpret_cast<uint32_t*>(this_ptr + 8);
        if (temp_value > *reinterpret_cast<uint32_t*>(this_ptr + 10))
        {
          *reinterpret_cast<uint32_t*>(this_ptr + 8) = *width_ptr;
          *width_ptr = temp_value;
        }
      }
      result = error_code[0];
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
      return result;
    }
}

#endif
