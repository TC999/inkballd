#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    BOOL __stdcall Helpers::SystemParametersInfoW(
            UINT action,
            UINT param,
            void* value,
            UINT flags,
            uint32_t* error_result,
            int* unused)
    {
      BOOL result; // esi
      uint32_t last_error; // eax
      const char* log_buffer[2]; // [esp+4h] [ebp-Ch] BYREF
      uint32_t error_code[1]; // [esp+Ch] [ebp-4h] BYREF

      error_code[0] = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "Helpers::SystemParametersInfoW", reinterpret_cast<int*>(error_code));
      result = SystemParametersInfoW(action, param, value, flags);
      if (!result)
      {
        last_error = GetLastError();
        if (last_error > 0)
          last_error = static_cast<uint16_t>(last_error) | 0x80070000;
        error_code[0] = last_error;
        if (WPP_GLOBAL_Control != &WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0)
          WPP_SF_d(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0x4Eu, &stru_10036F8, error_code[0]);
      }
      if (error_result)
        *error_result = error_code[0];
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return result;
    }
}
