#include <cstdint>

extern "C" {
    CSurface* CSurface::CSurface(CSurface* this_ptr)
    {
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSurface::CSurface", 0);
      *reinterpret_cast<uint32_t*>(this_ptr) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 32) = 0;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
