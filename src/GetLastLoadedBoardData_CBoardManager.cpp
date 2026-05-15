#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void* g_pLastLoadedLevel;
const uint8_t* GetLastLoadedBoardData_CBoardManager(CBoardManager* self)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardManager::GetLastLoadedBoardData", 0);
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return reinterpret_cast<const uint8_t*>(&g_pLastLoadedLevel);
}
