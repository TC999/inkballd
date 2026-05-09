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

extern "C" int GetRandomNumber(int max_value);

CBoardTile* __thiscall CBallManager::GetRandomBallLauncher(CBallManager *this)
{
    CBoardTile* random_launcher;
    uint32_t generator_count;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::GetRandomBallLauncher", 0);
    generator_count = this->generator_count;
    flag = 0;
    
    random_launcher = this->generators[GetRandomNumber(generator_count)];
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return random_launcher;
}
