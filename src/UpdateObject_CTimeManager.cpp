#include "global_types.h"
#include <cstdint>

extern "C" {
void UpdateObject_CTimeManager(CTimeManager* self, CTimeManager* this_ptr, uint32_t delta_time)
    {
      bool is_active; // zf
      uint32_t remaining_time; // ecx
      uint32_t adjusted_time; // ecx
      uint32_t centiseconds; // ecx
      uint32_t milliseconds; // eax
      uint32_t total_milliseconds; // eax
      uint8_t log_buffer[8]; // [esp+10h] [ebp-18h] BYREF
      int should_update_display; // [esp+18h] [ebp-10h]
      int cleanup_flag; // [esp+24h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CTimeManager::UpdateObject", 0);
      is_active = *reinterpret_cast<uint32_t*>(this_ptr + 14) == 0;
      cleanup_flag = 0;
      should_update_display = 0;
      if (!is_active)
      {
        if (*reinterpret_cast<uint32_t*>(this_ptr + 13))
        {
          KillPlayer(0);
        }
        else
        {
          remaining_time = *reinterpret_cast<uint32_t*>(this_ptr + 9);
          if (remaining_time != -1)
          {
            if (remaining_time > delta_time)
            {
              adjusted_time = remaining_time - delta_time;
              *reinterpret_cast<uint32_t*>(this_ptr + 9) = adjusted_time;
              if (adjusted_time < 0x2AF8) // 11000ms
              {
                *reinterpret_cast<uint32_t*>(this_ptr + 10) += delta_time;
                centiseconds = *reinterpret_cast<uint32_t*>(this_ptr + 10);
                *reinterpret_cast<uint32_t*>(this_ptr + 11) += delta_time;
                milliseconds = *reinterpret_cast<uint32_t*>(this_ptr + 11);
                if (centiseconds >= 0x14D) // 333ms
                {
                  is_active = *reinterpret_cast<uint32_t*>(this_ptr + 12) == 0;
                  *reinterpret_cast<uint32_t*>(this_ptr + 10) = 0;
                  should_update_display = 1;
                  *reinterpret_cast<uint32_t*>(this_ptr + 12) = is_active;
                }
                if (milliseconds >= 0x3E8) // 1000ms
                  *reinterpret_cast<uint32_t*>(this_ptr + 11) = 0;
              }
            }
            else
            {
              *reinterpret_cast<uint32_t*>(this_ptr + 9) = 0;
              *reinterpret_cast<uint32_t*>(this_ptr + 12) = 1;
            }
          }
        }
        total_milliseconds = *reinterpret_cast<uint32_t*>(this_ptr + 9);
        if (total_milliseconds >= 0x3E8 || *reinterpret_cast<uint32_t*>(this_ptr + 13)) // 1000ms
        {
          is_active = should_update_display == 1;
          *reinterpret_cast<uint32_t*>(this_ptr + 13) = 0;
          if (!is_active && total_milliseconds / 0x3E8 == dword_105C81C / 0x3E8u)
            goto LABEL_18;
        }
        else
        {
          *reinterpret_cast<uint32_t*>(this_ptr + 12) = 1;
          *reinterpret_cast<uint32_t*>(this_ptr + 13) = 1;
        }
        (*(void(__thiscall **)(CTimeManager*))(*reinterpret_cast<uint32_t*>(this_ptr + 4)))(this_ptr);
LABEL_18:
        dword_105C81C = *reinterpret_cast<uint32_t*>(this_ptr + 9);
      }
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}
