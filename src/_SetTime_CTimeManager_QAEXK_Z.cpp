#include "global_types.h"
#include <cstdint>

extern "C" {
    void CTimeManager::SetTime(CTimeManager* this_ptr, uint32_t time_value)
    {
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CTimeManager::SetTime", 0);
      cleanup_flag = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 13) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 9) = time_value;
      (*(void(__thiscall **)(CTimeManager*))(*reinterpret_cast<uint32_t*>(this_ptr + 4)))(this_ptr);
      cleanup_flag = -1;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
    }
}
