#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    namespace Helpers {
        class CLogBlock {
        public:
            CLogBlock(void* buffer, const char* message, int*);
            ~CLogBlock();
        };
    }
}

};

extern "C" void* g_pDisplay; // Global display instance
extern "C" void* g_pBallManagerSurface; // Global ball manager surface

int __thiscall CBallManager::InitSurface(CBallManager *this)
{
    int surface_result;
    int return_value;
    void* surface_data;
    uint32_t surface_size;
    uint8_t log_buffer[8];
    int log_data[3];
    int flag;

    log_data[0] = 0;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::InitSurface", log_data);
    surface_size = this->surface_size;
    surface_data = reinterpret_cast<void*>(this->surface_data);
    flag = 0;
    surface_result = CDisplay::CreateSurface(g_pDisplay, &g_pBallManagerSurface, surface_data, surface_size);
    flag = -1;
    log_data[0] = surface_result;
    return_value = surface_result;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return return_value;
}
