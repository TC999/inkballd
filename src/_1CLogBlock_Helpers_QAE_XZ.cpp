#include "global_types.h"
#include <cstdint>

extern "C" {
    void Helpers::CLogBlock::~CLogBlock(const char** this_ptr)
    {
      const char* log_info; // eax
      int error_code; // ecx
      void** control_ptr; // eax

      log_info = *this_ptr;
      if (!*this_ptr)
        goto LABEL_6;
      error_code = *reinterpret_cast<uint32_t*>(log_info);
      if (*reinterpret_cast<int*>(log_info) >= 0)
        goto LABEL_6;
      control_ptr = reinterpret_cast<void**>(WPP_GLOBAL_Control);
      if (WPP_GLOBAL_Control == &WPP_GLOBAL_Control)
        return;
      if ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4)
      {
        WPP_SF_sL(*reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control) + 2, 0xBu, &stru_10036F8, this_ptr[1], error_code);
LABEL_6:
        control_ptr = reinterpret_cast<void**>(WPP_GLOBAL_Control);
      }
      if (control_ptr != &WPP_GLOBAL_Control && (*reinterpret_cast<uint16_t*>(control_ptr + 7) & 0x400) != 0)
        WPP_SF_s(*reinterpret_cast<uint64_t*>(control_ptr) + 2, 0xCu, &stru_10036F8, this_ptr[1]);
    }
}
