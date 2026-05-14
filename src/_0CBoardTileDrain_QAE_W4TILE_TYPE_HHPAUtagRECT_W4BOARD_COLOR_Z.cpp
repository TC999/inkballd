#include "global_types.h"
#include <new>
#include <cstdint>

extern void* CBoardTileDrain_vftable;
CBoardTile* CBoardTileDrain_CBoardTileDrain(CBoardTileDrain* self, int tile_type, int x, int y, int rect_param, int color)
{
    uint8_t log_buffer[8];

    new ((CBoardTile*)self) CBoardTile();
    *reinterpret_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(&CBoardTileDrain_vftable);
    new (log_buffer) Helpers::CLogBlock(log_buffer, "CBoardTileDrain::CBoardTileDrain", 0);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 72) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 64) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 68) = tile_type;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 76) = x;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 80) = y;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 32) = rect_param;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 44) = color;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return (CBoardTile*)self;
}
