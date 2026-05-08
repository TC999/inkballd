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

struct CSurface {
    void* ddraw_surface; // offset 0x0
    // ... other members
};

struct IDirectDrawSurface7; // Forward declaration

IDirectDrawSurface7* __thiscall CSurface::GetDDrawSurface(CSurface *this)
{
    IDirectDrawSurface7* surface;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CSurface::GetDDrawSurface", 0);
    surface = reinterpret_cast<IDirectDrawSurface7*>(this->ddraw_surface);
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return surface;
}
