#include "global_types.h"
#include <cstdint>
#include <windows.h>
void GetCenterPoint_CBoardObject(CBoardObject* self, POINT* center_point)
{
    uint8_t log_buffer[8];
    int center_x;
    int center_y;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardObject::GetCenterPoint", 0);
    center_x = self->width >> 1;
    center_point->x = static_cast<int>(static_cast<double>(center_x) + self->position_x);
    center_y = self->height >> 1;
    center_point->y = static_cast<int>(static_cast<double>(center_y) + self->position_y);
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
