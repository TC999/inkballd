#include "global_types.h"
#include <cstdint>

extern "C" {
    CBoardObject* CBoardTile::CBoardTile(CBoardObject* this_ptr, int tile_type, int x, int y, int rect_param)
    {
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      CBoardObject::CBoardObject(this_ptr);
      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CBoardTile::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardTile::CBoardTile", 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 18) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 16) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 17) = tile_type;
      *reinterpret_cast<uint32_t*>(this_ptr + 19) = x;
      *reinterpret_cast<uint32_t*>(this_ptr + 20) = y;
      *reinterpret_cast<uint32_t*>(this_ptr + 8) = rect_param;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
