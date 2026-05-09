#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    namespace Helpers {
        class CLogBlock {
        public:
            CLogBlock(void* buffer, const char* message, int);
            ~CLogBlock();
        };
    }
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
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return distance_squared;
}
