#include "global_types.h"
#include <cstdint>
#include <windows.h>
int GetCurrBallPoint_CBall(CBall* self)
{
    int current_ball_point;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::GetCurrBallPoint", 0);
    current_ball_point = (self->best_point_index + self->current_point_index) % 32;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return current_ball_point;
}
