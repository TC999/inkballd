#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

int __stdcall CalcUnsqrtDistance(POINT* point1, POINT* point2)
{
    int distance_y_squared;
    int distance_squared;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CalcUnsqrtDistance", 0);
    distance_y_squared = point1->y - point2->y;
    distance_squared = distance_y_squared * distance_y_squared + 
                      (point1->x - point2->x) * (point1->x - point2->x);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return distance_squared;
}
