#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

extern "C" void* g_pBallManagerSurface; // Global ball manager surface

void CBallManager::Restore(CBallManager *this)
{
    IDirectDrawSurface7* ddraw_surface;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(&log_buffer), "CBallManager::Restore", 0);
    flag = 0;
    ddraw_surface = CSurface::GetDDrawSurface(g_pBallManagerSurface);
    ddraw_surface->Restore();
    (reinterpret_cast<void(*)(CBallManager*)>(this->restore_function))(this);
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}
