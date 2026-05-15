#include "global_types.h"
#include <cstdint>
#include <windows.h>
RECT* GetBitmapRect_CBitmapRects(CBitmapRects* self, int index)
{
    RECT* rect;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBitmapRects::GetBitmapRect", 0);
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return reinterpret_cast<RECT*>(reinterpret_cast<uint8_t*>(self) + 16 * index);
}
