#include <cstdint>
#include <cmath>
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
    uint32_t radius; // offset 0x18 (6 * 4)
    // ... other members
};

bool __thiscall CBall::BallsIntersect(CBall *this, const CBall *other_ball)
{
    double distance_y;
    double distance_x_squared;
    double distance_x;
    bool intersect_result;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::BallsIntersect", 0);
    distance_y = this->position_y - other_ball->position_y;
    distance_x_squared = distance_y * distance_y;
    distance_x = this->position_x - other_ball->position_x;
    intersect_result = static_cast<double>(other_ball->radius) * 0.5 + 0.5 * static_cast<double>(this->radius) > 
                       sqrt(distance_x * distance_x + distance_x_squared);
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return intersect_result;
}
