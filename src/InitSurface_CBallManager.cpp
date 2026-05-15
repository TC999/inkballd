#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

extern "C" void* g_pDisplay; // Global display instance
extern "C" void* g_pBallManagerSurface; // Global ball manager surface
int InitSurface_CBallManager(CBallManager* self)
{
    int surface_result;
    int return_value;
    void* surface_data;
    uint32_t surface_size;
    uint8_t log_buffer[8];
    int log_data[3];
    int flag;

    log_data[0] = 0;
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBallManager::InitSurface", log_data);
    surface_size = self->surface_size;
    surface_data = reinterpret_cast<void*>(self->surface_data);
    flag = 0;
    surface_result = CDisplay::CreateSurface(g_pDisplay, &g_pBallManagerSurface, surface_data, surface_size);
    flag = -1;
    log_data[0] = surface_result;
    return_value = surface_result;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return return_value;
}
