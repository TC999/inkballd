#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    BOOL __stdcall Helpers_UpdateWindow(HWND hWnd, HWND unused1, int* unused2)
    {
      BOOL result; // esi
      uint32_t last_error; // eax
      const char* log_buffer[2]; // [esp+4h] [ebp-Ch] BYREF
      uint32_t error_code[1]; // [esp+Ch] [ebp-4h] BYREF

      error_code[0] = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "Helpers::UpdateWindow", 0);
      result = UpdateWindow(hWnd);
      if (!result)
      {
        last_error = GetLastError();
        if (last_error > 0)
          last_error = static_cast<uint16_t>(last_error) | 0x80070000;
        error_code[0] = last_error;
        if ((uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(&WPP_GLOBAL_Control) + 28) & 4) != 0)
          WPP_SF_d(WPP_GLOBAL_Control + 2, 0x5Au, &stru_10036F8, error_code[0]);
      }
      if (unused1)
        *reinterpret_cast<uint32_t*>(unused1) = error_code[0];
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
      return result;
    }
}
