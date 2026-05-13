#include "global_types.h"
#include <cstdint>

extern void* CBoardTileBumper_vftable;

CBoardTile* CBoardTileBumper::CBoardTileBumper(CBoardTile* self, int x, int y, int rect_param, int color, int direction)
{
    uint8_t log_buffer[8];

    CBoardTile::CBoardTile(self);
    *reinterpret_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(&CBoardTileBumper_vftable);
    new (log_buffer) Helpers::CLogBlock(log_buffer, "CBoardTileBumper::CBoardTileBumper", 0);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 72) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 64) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 76) = x;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 80) = y;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 32) = rect_param;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 44) = color;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 68) = 11;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 88) = direction;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return self;
}
