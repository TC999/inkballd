#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

void __thiscall CBoardObject::GetCenterPoint(CBoardObject *this, POINT* center_point)
{
    uint8_t log_buffer[8];
    int center_x;
    int center_y;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardObject::GetCenterPoint", 0);
    center_x = this->width >> 1;
    center_point->x = static_cast<int>(static_cast<double>(center_x) + this->position_x);
    center_y = this->height >> 1;
    center_point->y = static_cast<int>(static_cast<double>(center_y) + this->position_y);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}

#endif
