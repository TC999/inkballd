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
    // ... members
};

int __thiscall CBall::GetPrevBallPoint(CBall *this)
{
    int prev_ball_point;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::GetPrevBallPoint", 0);
    flag = 0;
    int current_point = CBall::GetCurrBallPoint(this);
    if (current_point > 0)
        prev_ball_point = current_point - 1;
    else
        prev_ball_point = 31;
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return prev_ball_point;
}
