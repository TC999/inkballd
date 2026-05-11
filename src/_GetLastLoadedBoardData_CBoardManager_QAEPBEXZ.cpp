#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

extern "C" void* g_pLastLoadedLevel; // Global last loaded level

const uint8_t* __thiscall CBoardManager::GetLastLoadedBoardData(CBoardManager *this)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardManager::GetLastLoadedBoardData", 0);
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return reinterpret_cast<const uint8_t*>(&g_pLastLoadedLevel);
}

#endif
