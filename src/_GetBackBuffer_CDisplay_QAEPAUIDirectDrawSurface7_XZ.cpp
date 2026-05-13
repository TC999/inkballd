#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

IDirectDrawSurface7* CDisplay::GetBackBuffer()
{
    int v2;
    uint8_t v4[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CDisplay::GetBackBuffer", 0);
    v2 = *((uint32_t*)this + 3);
    reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
    return (IDirectDrawSurface7*)v2;
}
