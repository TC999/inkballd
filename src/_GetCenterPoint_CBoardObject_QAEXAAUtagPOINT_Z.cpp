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

struct CBoardObject {
    uint32_t width; // offset 0x18 (6 * 4)
    uint32_t height; // offset 0x1C (7 * 4)
    double position_x; // offset 0x10 (1 * 8)
    double position_y; // offset 0x18 (2 * 8)
    // ... other members
};

void __thiscall CBoardObject::GetCenterPoint(CBoardObject *this, POINT* center_point)
{
    uint8_t log_buffer[8];
    int center_x;
    int center_y;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardObject::GetCenterPoint", 0);
    center_x = this->width >> 1;
    center_point->x = static_cast<int>(static_cast<double>(center_x) + this->position_x);
    center_y = this->height >> 1;
    center_point->y = static_cast<int>(static_cast<double>(center_y) + this->position_y);
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
