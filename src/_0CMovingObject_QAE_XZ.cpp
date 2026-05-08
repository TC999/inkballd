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

struct CMovingObject : CBoardObject {
    double velocity_x; // offset 0x40 (8 * 8)
    double velocity_y; // offset 0x48 (9 * 8)
    double acceleration_x; // offset 0x50 (10 * 8)
    double acceleration_y; // offset 0x58 (11 * 8)
    // ... other members
};

extern "C" void* CInk_vftable; // Forward declaration of virtual table

CMovingObject* __thiscall CMovingObject::CMovingObject(CMovingObject *this)
{
    uint8_t log_buffer[8];

    CBoardObject::CBoardObject(this);
    this->vftable = &CInk_vftable;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CMovingObject::CMovingObject", 0);
    this->velocity_x = 0.0;
    this->velocity_y = 0.0;
    this->acceleration_x = 0.0;
    this->acceleration_y = 0.0;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return this;
}
