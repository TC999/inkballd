#include <cstdint>

extern "C" {
    int __stdcall WPP_INIT_CONTROL_ARRAY(void* control_array)
    {
      int result; // eax

      // Define a structure to make the code more readable
      struct WppControl {
          void* vtable;              // offset 0
          uint32_t unknown1;        // offset 16
          uint8_t flags1;            // offset 24
          uint8_t flags2;            // offset 25
          uint16_t reserved1;        // offset 26
          uint32_t unknown2;        // offset 28
          uint32_t padding1;        // offset 32
          uint32_t unknown3;        // offset 48
          uint8_t flags3;            // offset 56
          uint8_t flags4;            // offset 57
          uint16_t reserved2;        // offset 58
          uint32_t unknown4;        // offset 60
      };

      WppControl* ctrl = reinterpret_cast<WppControl*>(control_array);
      
      // Initialize the control structure
      ctrl->unknown1 = 0;
      ctrl->vtable = &unk_10B26E0;
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
