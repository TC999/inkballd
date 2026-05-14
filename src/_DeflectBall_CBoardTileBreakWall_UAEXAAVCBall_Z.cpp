#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void __stdcall PerformStandardWallDeflection(void* tile, CBall* ball);
extern "C" void __stdcall ConvertTileToFloor(void* tile);
extern "C" void __stdcall ScoreBreak(void* ball);
void DeflectBall_CBoardTileBreakWall(CBoardTileBreakWall* self, CBall* ball)
{
    uint32_t tile_type;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTileBreakWall::DeflectBall", 0);
    flag = 0;
    
    PerformStandardWallDeflection(self, ball);
    tile_type = self->tile_type;
    if (!tile_type || tile_type == ball->tile_type)
    {
        ConvertTileToFloor(self);
        ScoreBreak(ball);
    }
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}
