#include <cstdint>

extern "C" {
    CDisplay* CDisplay::CDisplay(CDisplay* this_ptr)
    {
      uint8_t log_buffer[8]; // [esp+8h] [ebp-8h] BYREF

      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CDisplay::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CDisplay::CDisplay", 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 1) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 2) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 3) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 4) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 5) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 6) = 0;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
