#include "global_types.h"
#include <cstdint>
#include <windows.h>

void UpdateObject_CBoardTileRLGray(CBoardTileRLGray* self, uint32_t delta_time)
{
    uint32_t animation_state;
    uint32_t color_index;
    uint32_t animation_timer;
    uint32_t state_timer;
    uint32_t current_color;
    uint32_t new_color_index;
    uint8_t log_buffer[8];
    int flag;
    uint32_t min_time;
    uint32_t max_time;

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)&log_buffer, "CBoardTileRLGray::UpdateObject", 0);
    self->animation_timer += delta_time;
    self->state_timer += delta_time;
    animation_state = self->animation_state;
    color_index = self->color_index;
    animation_timer = self->animation_timer;
    state_timer = self->state_timer;
    flag = 0;
    current_color = color_index;
    min_time = self->min_time;
    max_time = self->max_time;
    
    if (!animation_state)
    {
        if (animation_timer < min_time)
        {
            if (color_index > 0 && state_timer > 50)
            {
                new_color_index = color_index - 1;
LABEL_6:
                self->color_index = new_color_index;
LABEL_20:
                self->state_timer = 0;
                goto LABEL_21;
            }
            goto LABEL_21;
        }
        self->animation_state = 1;
LABEL_8:
        self->animation_timer = 0;
        goto LABEL_21;
    }
    
    if (animation_state == 1)
    {
        if (animation_timer > max_time)
        {
            self->animation_state = 0;
            goto LABEL_8;
        }
        if (BallOnTile(self))
            goto LABEL_21;
        self->animation_state = 2;
LABEL_19:
        self->animation_timer = 0;
        goto LABEL_20;
    }
    
    if (animation_timer >= max_time)
    {
        self->animation_state = 0;
        goto LABEL_19;
    }
    
    if (color_index < 4 && state_timer > 50)
    {
        new_color_index = color_index + 1;
        goto LABEL_6;
    }
    
LABEL_21:
    uint32_t final_color = self->color_index;
    if (final_color != current_color)
    {
        self->bitmap_rect = GetBitmapRect(5 * final_color + 77);
        UpdateBoardTile((void*)self);
        ShadowizeTile((CBoardTile*)self);
    }
    
    flag = -1;
    ((Helpers::CLogBlock *)&log_buffer)->~CLogBlock();
}
