#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

};

BallPoint* __thiscall CBall::GetPoint(CBall *this, int point_index)
{
    BallPoint* point;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::GetPoint", 0);
    uint32_t points_base = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*>(this) + 30);
    point = reinterpret_cast<BallPoint*>(points_base + 8 * point_index);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return point;
}

#endif
