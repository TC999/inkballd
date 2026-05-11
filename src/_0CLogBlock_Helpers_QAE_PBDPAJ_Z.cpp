#if 0
#include "global_types.h"
#include <cstdint>

extern "C" {
    Helpers::CLogBlock* Helpers::CLogBlock::CLogBlock(Helpers::CLogBlock* this_ptr, const char* function_name, int* error_code)
    {
      *reinterpret_cast<uint32_t*>(this_ptr + 1) = reinterpret_cast<uint32_t>(function_name);
      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(error_code);
      if (WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*reinterpret_cast<uint16_t*>(WPP_GLOBAL_Control + 14) & 0x400) != 0)
        WPP_SF_s(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0xAu, &stru_10036F8, function_name);
      return this_ptr;
    }
}

#endif
