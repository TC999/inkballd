#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

int CBall::GetPrevBallPoint()
{
    int prev_ball_point;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::GetPrevBallPoint", 0);
    flag = 0;
    int current_point = CBall::GetCurrBallPoint(this);
    if (current_point > 0)
        prev_ball_point = current_point - 1;
    else
        prev_ball_point = 31;
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return prev_ball_point;
}
