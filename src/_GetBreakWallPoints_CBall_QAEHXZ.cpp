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
    extern int BreakPoints[256]; // Global array
}

struct CBall {
    uint32_t break_point_index; // offset 0x2C (11 * 4)
    // ... other members
};

int* __thiscall CBall::GetBreakWallPoints(CBall *this)
{
    int* break_point_array;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::GetBreakWallPoints", 0);
    break_point_array = &BreakPoints[this->break_point_index];
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return break_point_array;
}
