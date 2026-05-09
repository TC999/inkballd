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

void __thiscall CBallManager::AddBallGenerator(CBallManager *this, CBoardTile* tile)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::AddBallGenerator", 0);
    
    uint32_t current_count = this->generator_count++;
    this->generators[current_count] = tile;
    
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
