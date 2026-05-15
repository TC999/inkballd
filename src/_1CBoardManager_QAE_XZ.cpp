#include "global_types.h"
#include <cstdint>
#include <windows.h>

CBoardManager::~CBoardManager()
{
    uint32_t current_difficulty;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardManager::~CBoardManager", 0);
    current_difficulty = *((uint32_t*)self + 1);
    flag = 0;
    
    CRegistryManager::WriteDifficulty(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager), current_difficulty);
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
