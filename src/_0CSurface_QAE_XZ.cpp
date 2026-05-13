#include "global_types.h"
#include <cstdint>

extern "C" {
    CSurface::CSurface()
    {
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSurface::CSurface", 0);
      *((uint32_t*)this + 0) = 0;
      *((uint32_t*)this + 8) = 0;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}
