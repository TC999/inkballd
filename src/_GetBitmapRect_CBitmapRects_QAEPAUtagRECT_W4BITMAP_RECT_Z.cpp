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

RECT* __thiscall CBitmapRects::GetBitmapRect(CBitmapRects *this, int index)
{
    RECT* rect;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBitmapRects::GetBitmapRect", 0);
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return reinterpret_cast<RECT*>(reinterpret_cast<uint8_t*>(this) + 16 * index);
}
