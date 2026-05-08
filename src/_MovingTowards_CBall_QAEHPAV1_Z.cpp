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

struct CBall {
    double position_x; // offset 0x10 (1 * 8)
    double position_y; // offset 0x18 (2 * 8)
    double velocity_x; // offset 0x20 (8 * 8)
    double velocity_y; // offset 0x28 (9 * 8)
    // ... other members
};

bool __thiscall CBall::MovingTowards(CBall *this, CBall *other_ball)
{
    bool result; // esi
    uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::MovingTowards", 0);
    result = ((other_ball->position_y - this->position_y) * this->velocity_y +
              (other_ball->position_x - this->position_x) * this->velocity_x) > 0.0;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return result;
}
