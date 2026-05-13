#include "global_types.h"
#include <cstdint>

extern void* CBoardTile_vftable;

CBoardTile* CBoardTile::CBoardTile(CBoardTile* self, int tile_type, int x, int y, int rect_param)
{
    uint8_t log_buffer[8];

    CBoardObject::CBoardObject(self);
    *reinterpret_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(&CBoardTile_vftable);
    new (log_buffer) Helpers::CLogBlock(log_buffer, "CBoardTile::CBoardTile", 0);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 72) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 64) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 68) = tile_type;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 76) = x;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 80) = y;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 32) = rect_param;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return self;
}
