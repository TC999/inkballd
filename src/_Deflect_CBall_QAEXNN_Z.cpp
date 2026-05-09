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

void __thiscall CBall::Deflect(CBall *this, double impulse_x, double impulse_y)
{
    double dot_product; // st5
    uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::Deflect", 0);
    dot_product = impulse_x * this->velocity_x + impulse_y * this->velocity_y;
    this->velocity_x = this->velocity_x - impulse_x * ((dot_product + dot_product) / (impulse_x * impulse_x + impulse_y * impulse_y));
    this->velocity_y = this->velocity_y - (dot_product + dot_product) / (impulse_x * impulse_x + impulse_y * impulse_y) * impulse_y;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
