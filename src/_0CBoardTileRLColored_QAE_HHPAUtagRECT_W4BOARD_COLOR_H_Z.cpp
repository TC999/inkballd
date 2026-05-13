#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern void* CBoardTileRLColored_vftable;
extern void AddGameObjectToUpdateList(void* game_object);
extern void AddRLColoredWallToList(void* wall_tile);
CBoardTile* CBoardTileRLColored_CBoardTileRLColored(CBoardTileRLColored* self, CBoardTile* self,
    int x,
    int y,
    int bitmap_rect,
    int tile_type,
    int initial_color)
{
    uint8_t log_buffer[16];

    CBoardTile::CBoardTile(self);
    self->vftable = &CBoardTileRLColored_vftable;
    new (log_buffer) Helpers::CLogBlock(log_buffer, "CBoardTileRLColored::CBoardTileRLColored", 0);

    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 76) = x;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 80) = y;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 32) = bitmap_rect;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 68) = tile_type;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 44) = initial_color;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 96) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 92) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 88) = (initial_color != 0) ? 2 : 0;

    AddGameObjectToUpdateList(self);
    AddRLColoredWallToList(self);

    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return self;
}
