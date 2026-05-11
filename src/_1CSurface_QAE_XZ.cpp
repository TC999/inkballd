#if 0
#include "global_types.h"
#include <cstdint>

extern "C" {
    void CSurface::~CSurface(CSurface* this_ptr)
    {
      int interface_ptr; // eax
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSurface::~CSurface", 0);
      interface_ptr = *reinterpret_cast<uint32_t*>(this_ptr);
      cleanup_flag = 0;
      if (interface_ptr)
      {
        (*(void(__stdcall**)(uint32_t))(*reinterpret_cast<uint32_t*>(interface_ptr) + 8))(interface_ptr);
        *reinterpret_cast<uint32_t*>(this_ptr) = 0;
      }
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

#endif
