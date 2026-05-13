#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
IDirectDraw7* GetDirectDraw_CDisplay(CDisplay* self)
{
    int v2;
    uint8_t v4[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CDisplay::GetDirectDraw", 0);
    v2 = *((uint32_t*)self + 1);
    reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
    return (IDirectDraw7*)v2;
}
