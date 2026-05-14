#include "global_types.h"
#include <cstdint>

extern "C" {
  void CSurface_CSurface(CSurface* self)
    {
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSurface::CSurface", 0);
      *((uint32_t*)self + 0) = 0;
      *((uint32_t*)self + 8) = 0;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}
