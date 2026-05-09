#include "global_types.h"
#include <cstdint>

extern "C" {
    void __stdcall WppCleanupUm()
    {
      uint64_t* control_ptr; // esi

      control_ptr = WPP_GLOBAL_Control;
      if (WPP_GLOBAL_Control != &WPP_GLOBAL_Control)
      {
        while (control_ptr)
        {
          if (control_ptr[1])
          {
            UnregisterTraceGuids(control_ptr[1]);
            *reinterpret_cast<uint32_t*>(control_ptr + 2) = 0;
            *reinterpret_cast<uint32_t*>(control_ptr + 3) = 0;
          }
          control_ptr = *reinterpret_cast<uint64_t**>(control_ptr);
        }
        WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
      }
    }
}
