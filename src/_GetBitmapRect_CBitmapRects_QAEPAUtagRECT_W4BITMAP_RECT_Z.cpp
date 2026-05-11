#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

RECT* __thiscall CBitmapRects::GetBitmapRect(CBitmapRects *this, int index)
{
    RECT* rect;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBitmapRects::GetBitmapRect", 0);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return reinterpret_cast<RECT*>(reinterpret_cast<uint8_t*>(this) + 16 * index);
}

#endif
