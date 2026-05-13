#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

extern "C" bool BallOnTile(void* tile);
extern "C" void* GetBitmapRect(int index);
extern "C" void UpdateBoardTile(void* tile);
extern "C" void ShadowizeTile(void* tile);

void UpdateObject_CBoardTileRLColored(CBoardTileRLColored *this, uint32_t delta_time)
{
    uint32_t animation_state;
    uint32_t color_index;
    uint32_t animation_timer;
    uint32_t current_color;
    uint32_t new_color_index;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTileRLColored::UpdateObject", 0);
    this->animation_timer += delta_time;
    animation_state = this->animation_state;
    color_index = this->color_index;
    animation_timer = this->animation_timer;
    flag = 0;
    current_color = color_index;
    
    if (animation_state)
    {
        if (animation_state == 1)
        {
            if (BallOnTile(this))
                goto LABEL_13;
            this->animation_state = 2;
            goto LABEL_12;
        }
        if (color_index < 4 && animation_timer > 50)
        {
            new_color_index = color_index + 1;
            goto LABEL_11;
        }
    }
    else if (color_index > 0 && animation_timer > 50)
    {
        new_color_index = color_index - 1;
LABEL_11:
        this->color_index = new_color_index;
LABEL_12:
        this->animation_timer = 0;
    }
    
LABEL_13:
    uint32_t final_color = this->color_index;
    if (final_color != current_color)
    {
        this->bitmap_rect = GetBitmapRect(5 * final_color + this->tile_type + 77);
        UpdateBoardTile(this);
        ShadowizeTile(this);
    }
    
    flag = -1;
    ((Helpers::CLogBlock *)&log_buffer)->~CLogBlock();
}
