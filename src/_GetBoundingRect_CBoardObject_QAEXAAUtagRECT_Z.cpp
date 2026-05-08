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

void __thiscall CBoardObject::GetBoundingRect(CBoardObject *this, RECT* bounding_rect)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardObject::GetBoundingRect", 0);
    bounding_rect->left = static_cast<int>(this->position_x);
    bounding_rect->right = static_cast<int>(static_cast<double>(this->width) + this->position_x);
    bounding_rect->top = static_cast<int>(this->position_y);
    bounding_rect->bottom = static_cast<int>(static_cast<double>(this->height) + this->position_y);
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
