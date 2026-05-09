#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    namespace Helpers {
        class CLogBlock {
        public:
            CLogBlock(void* buffer, const char* message, int);
            ~CLogBlock();
        };
    }
}

};

extern "C" void* CBoardTileRLColored_vftable; // Forward declaration of virtual table
extern "C" void AddGameObjectToUpdateList(void* game_object);
extern "C" void AddRLColoredWallToList(void* wall_tile);

CBoardTile* __thiscall CBoardTileRLColored::CBoardTileRLColored(
    CBoardTile *this,
    int x,
    int y,
    int bitmap_rect,
    int tile_type,
    int initial_color)
{
    uint8_t log_buffer[16];
    int flag;

    CBoardTile::CBoardTile(this);
    this->vftable = &CBoardTileRLColored_vftable;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTileRLColored::CBoardTileRLColored", 0);
    flag = 0;
    
    this->x_coord = x;
    this->y_coord = y;
    this->bitmap_rect = reinterpret_cast<void*>(bitmap_rect);
    this->tile_type = tile_type;
    this->color_index = initial_color;
    this->min_color = 0;
    this->animation_timer = 0;
    this->animation_state = initial_color != 0 ? 2 : 0;
    
    AddGameObjectToUpdateList(this);
    AddRLColoredWallToList(this);
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return this;
}
