#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

extern "C" int GetRandomNumber(int max_value);
CBoardTile* GetRandomBallLauncher_CBallManager(CBallManager* self)
{
    CBoardTile* random_launcher;
    uint32_t generator_count;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBallManager::GetRandomBallLauncher", 0);
    generator_count = self->generator_count;
    flag = 0;

    random_launcher = self->generators[GetRandomNumber(generator_count)];

    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return random_launcher;
}
