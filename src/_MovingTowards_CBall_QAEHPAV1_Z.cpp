#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

bool __thiscall CBall::MovingTowards(CBall *this, CBall *other_ball)
{
    bool result; // esi
    uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::MovingTowards", 0);
    result = ((other_ball->position_y - this->position_y) * this->velocity_y +
              (other_ball->position_x - this->position_x) * this->velocity_x) > 0.0;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return result;
}

#endif
