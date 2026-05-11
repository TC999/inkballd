#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

extern "C" CRegistryManager g_CRegistryManager; // Global registry manager

CBoardManager::~CBoardManager(CBoardManager *this)
{
    uint32_t current_difficulty;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardManager::~CBoardManager", 0);
    current_difficulty = this->difficulty_level;
    flag = 0;
    
    CRegistryManager::WriteDifficulty(&g_CRegistryManager, current_difficulty);
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}

#endif
