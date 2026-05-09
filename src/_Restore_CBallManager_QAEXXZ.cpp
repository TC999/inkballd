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

extern "C" void* g_pBallManagerSurface; // Global ball manager surface

void __thiscall CBallManager::Restore(CBallManager *this)
{
    IDirectDrawSurface7* ddraw_surface;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::Restore", 0);
    flag = 0;
    ddraw_surface = CSurface::GetDDrawSurface(g_pBallManagerSurface);
    ddraw_surface->lpVtbl->Restore(ddraw_surface);
    (reinterpret_cast<void(__thiscall*)(CBallManager*)>(this->restore_function))(this);
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
