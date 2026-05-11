#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

IDirectDrawSurface7* __thiscall CSurface::GetDDrawSurface(CSurface *this)
{
    IDirectDrawSurface7* surface;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CSurface::GetDDrawSurface", 0);
    surface = reinterpret_cast<IDirectDrawSurface7*>(this->ddraw_surface);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return surface;
}

#endif
