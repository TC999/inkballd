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

uint32_t __thiscall CBall::AddRef(CBall *this)
{
    uint32_t result; // esi
    uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::AddRef", 0);
    result = ++reinterpret_cast<uint32_t*>(this)[34];
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return result;
}
