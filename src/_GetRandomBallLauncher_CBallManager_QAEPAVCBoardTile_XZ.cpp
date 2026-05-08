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

struct CBoardTile; // Forward declaration

struct CBallManager {
    uint32_t generator_count; // offset 0x50 (20 * 4)
    CBoardTile* generators[16]; // offset 0x54 (21 * 4, 64 bytes total)
    // ... other members
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
