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

struct CBoardTileBreakWall {
    uint32_t tile_type; // offset 0x2C (11 * 4)
    // ... members
};

struct CBall; // Forward declaration

extern "C" void PerformStandardWallDeflection(void* tile, CBall* ball);
extern "C" void ConvertTileToFloor(void* tile);
extern "C" void ScoreBreak(CBall* ball);

void __thiscall CBoardTileBreakWall::DeflectBall(CBoardTileBreakWall *this, CBall* ball)
{
    uint32_t tile_type;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTileBreakWall::DeflectBall", 0);
    flag = 0;
    
    PerformStandardWallDeflection(this, ball);
    tile_type = this->tile_type;
    if (!tile_type || tile_type == ball->tile_type)
    {
        ConvertTileToFloor(this);
        ScoreBreak(ball);
    }
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
