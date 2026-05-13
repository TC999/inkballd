#if 0
#include "global_types.h"
#include <cstdint>
#include <cmath>
#include <windows.h>
bool __thiscall CBall::BallsIntersect(CBall *this, const CBall *other_ball)
{
    double distance_y;
    double distance_x_squared;
    double distance_x;
    bool intersect_result;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::BallsIntersect", 0);
    distance_y = this->position_y - other_ball->position_y;
    distance_x_squared = distance_y * distance_y;
    distance_x = this->position_x - other_ball->position_x;
    intersect_result = static_cast<double>(other_ball->radius) * 0.5 + 0.5 * static_cast<double>(this->radius) > 
                       sqrt(distance_x * distance_x + distance_x_squared);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return intersect_result;
}

#endif