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

struct BOARDHIST {
    uint32_t history[10]; // Array to store history
    uint32_t count; // offset 0x28 (10 * 4)
    // ... other members
};

int __stdcall fPrevSeen(int value, BOARDHIST* history, int max_size)
{
    uint32_t current_count;
    uint32_t search_index;
    uint32_t shift_index;
    uint32_t final_count;
    int found;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "fPrevSeen", 0);
    current_count = history->count;
    search_index = 0;
    flag = 0;
    
    if (current_count <= 0)
    {
LABEL_4:
        if (current_count < 10 && current_count + 1 < max_size)
            history->count = current_count + 1;
        final_count = history->count;
        if (final_count > 1)
        {
            while (--final_count > 0)
                history->history[final_count] = history->history[final_count - 1];
        }
        history->history[0] = value;
        found = 0;
    }
    else
    {
        while (value != history->history[search_index])
        {
            if (++search_index >= current_count)
                goto LABEL_4;
        }
        found = 1;
    }
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return found;
}
