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
    extern int DrainPoints[256]; // Global array
}

};

int* __thiscall CBall::GetDrainPoints(CBall *this)
{
    int* drain_point_array;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::GetDrainPoints", 0);
    drain_point_array = &DrainPoints[this->drain_point_index];
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return drain_point_array;
}
