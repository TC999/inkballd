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

};

};

BallPoint* __thiscall CBall::GetNextPoint(CBall *this)
{
    int current_index;
    BallPoint* next_point;
    uint32_t points_base;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::GetNextPoint", 0);
    current_index = this->current_point_index;
    if (current_index <= 16)
    {
        points_base = *reinterpret_cast<uint32_t*>(reinterpret_cast<uint32_t*>(this) + 30);
        next_point = reinterpret_cast<BallPoint*>(points_base + 8 * ((current_index + this->best_point_index) % 32));
        this->current_point_index = current_index + 1;
    }
    else
    {
        this->current_point_index = 0;
        next_point = nullptr;
    }
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return next_point;
}
