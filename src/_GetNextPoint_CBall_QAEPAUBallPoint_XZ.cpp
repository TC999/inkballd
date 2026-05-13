#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}
BallPoint* GetNextPoint_CBall(CBall* self)
{
    int current_index;
    BallPoint* next_point;
    uint32_t points_base;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::GetNextPoint", 0);
    current_index = self->current_point_index;
    if (current_index <= 16)
    {
        points_base = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*>(self) + 30);
        next_point = reinterpret_cast<BallPoint*>(points_base + 8 * ((current_index + self->best_point_index) % 32));
        self->current_point_index = current_index + 1;
    }
    else
    {
        self->current_point_index = 0;
        next_point = nullptr;
    }
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return next_point;
}
