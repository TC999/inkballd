#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

void __thiscall CBallManager::AddBallGenerator(CBallManager *this, CBoardTile* tile)
{
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::AddBallGenerator", 0);
    
    uint32_t current_count = this->generator_count++;
    this->generators[current_count] = tile;
    
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}

#endif
