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
