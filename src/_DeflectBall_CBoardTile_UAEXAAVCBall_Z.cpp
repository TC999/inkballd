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

void __thiscall CBoardTile::DeflectBall(CBoardTile *this, CBall* ball)
{
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTile::DeflectBall", 0);
    flag = 0;
    
    CBall::SetTallness(ball, nullptr);
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
