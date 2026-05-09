#include "global_types.h"
#include <cstdint>

extern "C" {
    CBoardTile* CBoardTileChevron::CBoardTileChevron(CBoardTile* this_ptr, int x, int y, int rect_param, int direction)
    {
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      CBoardTile::CBoardTile(this_ptr);
      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CBoardTileChevron::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardTileChevron::CBoardTileChevron", 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 18) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 16) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 19) = x;
      *reinterpret_cast<uint32_t*>(this_ptr + 20) = y;
      *reinterpret_cast<uint32_t*>(this_ptr + 22) = direction;
      *reinterpret_cast<uint32_t*>(this_ptr + 8) = rect_param;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
