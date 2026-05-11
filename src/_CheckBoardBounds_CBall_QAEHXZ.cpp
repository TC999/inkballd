#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
extern void GetBoardRect(RECT* rect);
}

};

int __thiscall CBall::CheckBoardBounds(CBall *this)
{
    int collision_occurred = 0;
    double left_bound;
    int right_edge;
    double top_bound;
    int bottom_edge;
    RECT board_rect;
    uint8_t log_buffer[8];
    int edge_distance;
    int flag;

    collision_occurred = 0;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::CheckBoardBounds", 0);
    flag = 0;
    GetBoardRect(&board_rect);
    left_bound = static_cast<double>(board_rect.left);
    if (left_bound <= this->position_x)
    {
        right_edge = board_rect.right - this->board_left;
        edge_distance = right_edge;
        if (static_cast<double>(right_edge) >= this->position_x)
            goto LABEL_5;
        edge_distance = right_edge - 1;
        left_bound = static_cast<double>(right_edge - 1);
    }
    this->position_x = left_bound;
    collision_occurred = 1;
    this->velocity_x = -this->velocity_x;
LABEL_5:
    top_bound = static_cast<double>(board_rect.top);
    if (top_bound > this->position_y)
    {
LABEL_8:
        this->position_y = top_bound;
        collision_occurred = 1;
        this->velocity_y = -this->velocity_y;
        goto LABEL_9;
    }
    bottom_edge = board_rect.bottom - this->board_top;
    edge_distance = bottom_edge;
    if (static_cast<double>(bottom_edge) < this->position_y)
    {
        edge_distance = bottom_edge - 1;
        top_bound = static_cast<double>(bottom_edge - 1);
        goto LABEL_8;
    }
LABEL_9:
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return collision_occurred;
}

#endif
