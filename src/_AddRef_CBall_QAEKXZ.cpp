#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

uint32_t __thiscall CBall::AddRef(CBall *this)
{
    uint32_t result; // esi
    uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::AddRef", 0);
    result = ++reinterpret_cast<uint32_t*>(this)[34];
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return result;
}

#endif
