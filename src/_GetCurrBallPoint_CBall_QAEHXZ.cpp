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

int __thiscall CBall::GetCurrBallPoint(CBall *this)
{
    int current_ball_point;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::GetCurrBallPoint", 0);
    current_ball_point = (this->best_point_index + this->current_point_index) % 32;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return current_ball_point;
}
