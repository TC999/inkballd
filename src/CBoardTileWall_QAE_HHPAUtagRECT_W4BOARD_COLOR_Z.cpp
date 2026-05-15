#include "global_types.h"
#include <new>
#include <cstdint>

extern void* CBoardTileWall_vftable;
CBoardTile* CBoardTileWall_CBoardTileWall(CBoardTileWall* self, int x, int y, int rect_param, int color)
{
    uint8_t log_buffer[8];

    new ((CBoardTile*)self) CBoardTile();
    *reinterpret_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(&CBoardTileWall_vftable);
    new (log_buffer) Helpers::CLogBlock(log_buffer, "CBoardTileWall::CBoardTileWall", 0);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 64) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 76) = x;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 80) = y;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 32) = rect_param;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 68) = 6;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 72) = 4;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 44) = color;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return (CBoardTile*)self;
}
