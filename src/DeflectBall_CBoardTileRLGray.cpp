#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void PerformStandardWallDeflection(void* tile, CBall* ball);
void DeflectBall_CBoardTileRLGray(CBoardTileRLGray* self, CBall* ball)
{
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTileRLGray::DeflectBall", 0);
    flag = 0;
    
    PerformStandardWallDeflection(self, ball);
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}
