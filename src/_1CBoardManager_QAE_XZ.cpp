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

struct CBoardManager {
    uint32_t difficulty_level; // offset 0x82201 (33281 * 4)
    // ... other members
};

struct CRegistryManager; // Forward declaration

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
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
