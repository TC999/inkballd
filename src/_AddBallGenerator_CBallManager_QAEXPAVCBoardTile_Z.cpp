#include "global_types.h"
#include <cstdint>
#include <windows.h>

void CBallManager::AddBallGenerator(CBallManager* self, CBoardTile* tile)
{
    uint8_t log_buffer[8];
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBallManager::AddBallGenerator", 0);
    *((uint32_t *)self + 20) = (uint32_t)tile;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
