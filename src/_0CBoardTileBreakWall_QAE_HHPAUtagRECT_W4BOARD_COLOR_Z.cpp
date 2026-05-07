#include <cstdint>

extern "C" {
    CBoardTile* CBoardTileBreakWall::CBoardTileBreakWall(CBoardTile* this_ptr, int x, int y, int rect_param, int color)
    {
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      CBoardTile::CBoardTile(this_ptr);
      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CBoardTileBreakWall::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardTileBreakWall::CBoardTileBreakWall", 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 22) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 16) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 19) = x;
      *reinterpret_cast<uint32_t*>(this_ptr + 20) = y;
      *reinterpret_cast<uint32_t*>(this_ptr + 8) = rect_param;
      *reinterpret_cast<uint32_t*>(this_ptr + 17) = 9;
      *reinterpret_cast<uint32_t*>(this_ptr + 18) = 4;
      *reinterpret_cast<uint32_t*>(this_ptr + 11) = color;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
