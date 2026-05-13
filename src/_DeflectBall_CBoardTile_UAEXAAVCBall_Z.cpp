#include "global_types.h"
#include <cstdint>
#include <windows.h>

void CBoardTile::DeflectBall(CBall* ball)
{
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTile::DeflectBall", 0);
    flag = 0;
    
    CBall::SetTallness(ball, nullptr);
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}
