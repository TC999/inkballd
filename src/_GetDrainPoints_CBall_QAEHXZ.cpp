#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
extern int DrainPoints[256];
}
int* GetDrainPoints_CBall(CBall* self)
{
    int* drain_point_array;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::GetDrainPoints", 0);
    drain_point_array = &DrainPoints[self->drain_point_index];
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return drain_point_array;
}
