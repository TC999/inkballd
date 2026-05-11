#include "global_types.h"
#include <cstdint>

extern "C" {
    int __stdcall WPP_INIT_CONTROL_ARRAY(void* control_array)
    {
      int result; // eax

      WppControl* ctrl = reinterpret_cast<WppControl*>(control_array);
      
      // Initialize the control structure
      ctrl->unknown1 = 0;
      ctrl->vtable = reinterpret_cast<uint32_t>(&unk_10B26E0);
      ctrl->flags1 = 1;
      ctrl->flags2 = 2;
      ctrl->reserved1 = 0;
      ctrl->unknown2 = 0;
      
      result = reinterpret_cast<int>(control_array) + 32;
      
      // Initialize the second part of the structure
      ctrl->padding1 = 0;
      ctrl->unknown3 = 0;
      ctrl->flags3 = 1;
      ctrl->flags4 = 2;
      ctrl->reserved2 = 0;
      ctrl->unknown4 = 0;
      
      return result;
    }
}
