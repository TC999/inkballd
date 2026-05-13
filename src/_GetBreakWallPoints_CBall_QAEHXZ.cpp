#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
extern int BreakPoints[256];
}

int* CBall::GetBreakWallPoints()
{
    int* break_point_array;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::GetBreakWallPoints", 0);
    break_point_array = &BreakPoints[this->break_point_index];
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return break_point_array;
}
