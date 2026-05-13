#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

bool MovingTowards_CBall(CBall *self, CBall *other_ball)
{
    bool result; // esi
    uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(&log_buffer), "CBall::MovingTowards", 0);
    result = ((other_ball->position_y - self->position_y) * self->velocity_y +
              (other_ball->position_x - self->position_x) * self->velocity_x) > 0.0;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return result;
}
