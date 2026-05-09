#include "global_types.h"
#include <cstdint>

extern "C" {
    BOOL __cdecl _ValidateImageBase(const void* image_base)
    {
      uint32_t optional_header_offset; // eax

      if (*reinterpret_cast<const uint16_t*>(image_base) == 23117 && 
          (optional_header_offset = reinterpret_cast<uint32_t>(image_base) + *reinterpret_cast<const uint32_t*>(reinterpret_cast<const uint8_t*>(image_base) + 60),
           *reinterpret_cast<const uint32_t*>(reinterpret_cast<const uint8_t*>(image_base) + optional_header_offset) == 17744))
        return *reinterpret_cast<const uint16_t*>(reinterpret_cast<const uint8_t*>(image_base) + optional_header_offset + 24) == 267;
      else
        return 0;
    }
}
