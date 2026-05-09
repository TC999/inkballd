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

extern "C" void* g_pLastLoadedLevel; // Global last loaded level

const uint8_t* __thiscall CBoardManager::GetLastLoadedBoardData(CBoardManager *this)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardManager::GetLastLoadedBoardData", 0);
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return reinterpret_cast<const uint8_t*>(&g_pLastLoadedLevel);
}
