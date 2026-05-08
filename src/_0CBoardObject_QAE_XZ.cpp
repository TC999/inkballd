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
    // Virtual table pointer (vftable)
    void* vftable; // offset 0x0
    uint32_t unknown_field_1; // offset 0x8
    double position_x; // offset 0x10 (1 * 8)
    double position_y; // offset 0x18 (2 * 8)
    uint32_t unknown_field_2; // offset 0x20 (10 * 4)
    uint32_t unknown_field_3; // offset 0x24 (11 * 4)
    double scale_x; // offset 0x30 (6 * 8)
    double scale_y; // offset 0x38 (7 * 8)
    uint32_t width; // offset 0x40 (6 * 4)
    uint32_t height; // offset 0x44 (7 * 4)
    // ... other members
};

extern "C" void* CInk_vftable; // Forward declaration of virtual table

CBoardObject* __thiscall CBoardObject::CBoardObject(CBoardObject *this)
{
    uint8_t log_buffer[8];

    this->vftable = &CInk_vftable;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardObject::CBoardObject", 0);
    this->unknown_field_1 = 0;
    this->position_x = 0.0;
    this->unknown_field_2 = 0;
    this->position_y = 0.0;
    this->unknown_field_3 = 0;
    this->scale_x = 1.0;
    this->scale_y = 1.0;
    this->width = 32;
    this->height = 32;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return this;
}
