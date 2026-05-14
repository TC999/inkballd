#include "global_types.h"
#include <cstdint>
#include <windows.h>
#include <shlwapi.h>

extern "C" {
int __stdcall TabQueryPolicyValue_TabUtils(void* _self, LPCWSTR value_name,
            const uint16_t* default_data,
            uint32_t* result_data,
            int* data_type,
            int* status)
    {
      int reg_result; // eax
      int user_result; // eax
      int return_code; // esi
      const char* log_buffer[2]; // [esp+Ch] [ebp-10h] BYREF
      DWORD data_size; // [esp+14h] [ebp-8h] BYREF
      int error_code; // [esp+18h] [ebp-4h] BYREF

  error_code = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)log_buffer, "TabUtils::TabQueryPolicyValue", &error_code);
  if (value_name && result_data)
  {
    *result_data = (uint32_t)(uintptr_t)default_data;
    uint16_t* local_default = 0;
    data_size = 4;
    reg_result = SHRegGetValueW(
                   HKEY_LOCAL_MACHINE,
                   L"SOFTWARE\\Policies\\Microsoft\\TabletPC",
                   value_name,
                   SRRF_RT_REG_DWORD,
                   0,
                   &local_default,
                   &data_size);
    if (reg_result)
    {
      if (reg_result == 2)
      {
        data_size = 4;
        local_default = 0;
        user_result = SHRegGetValueW(
                       HKEY_CURRENT_USER,
                       L"SOFTWARE\\Policies\\Microsoft\\TabletPC",
                       value_name,
                       SRRF_RT_REG_DWORD,
                       0,
                       &local_default,
                       &data_size);
        if (user_result)
        {
          if (user_result != 2)
          {
            if (user_result > 0)
              user_result = static_cast<uint16_t>(user_result) | 0x80070000;
            error_code = user_result;
            if ((uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0)
              WPP_SF_d(*(uint64_t*)((uint8_t*)WPP_GLOBAL_Control + 16), 0xCu, &stru_1003974, error_code);
          }
        }
        else
        {
          *result_data = (uint32_t)(local_default != 0);
          if (data_type)
            *data_type = 0;
        }
      }
      else
      {
        if (reg_result > 0)
          reg_result = static_cast<uint16_t>(reg_result) | 0x80070000;
        error_code = reg_result;
        if ((uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0)
          WPP_SF_d(*(uint64_t*)((uint8_t*)WPP_GLOBAL_Control + 16), 0xBu, &stru_1003974, error_code);
      }
    }
    else
    {
      *result_data = (uint32_t)(local_default != 0);
      if (data_type)
        *data_type = 1;
    }
  }
  else
  {
    error_code = -2147467261;
    if ((uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0)
      WPP_SF_d(*(uint64_t*)((uint8_t*)WPP_GLOBAL_Control + 16), 0xAu, &stru_1003974, 3);
  }
  return_code = error_code;
  ((Helpers::CLogBlock *)log_buffer)->~CLogBlock();
  return return_code;
}
}
