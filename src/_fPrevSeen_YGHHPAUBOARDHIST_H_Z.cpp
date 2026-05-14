#include "global_types.h"
#include <cstdint>
#include <windows.h>
#include <new>

extern "C" {
bool fPrevSeen(void* board_hist, int value)
{
    BOARDHIST* history = reinterpret_cast<BOARDHIST*>(board_hist);
    uint32_t current_count;
    uint32_t search_index;
    uint32_t shift_index;
    uint32_t final_count;
    int found;
    uint8_t log_buffer[16];
    int flag;

    new (log_buffer) Helpers::CLogBlock(log_buffer, "fPrevSeen", 0);
    current_count = history->count;
    search_index = 0;
    flag = 0;
    
    if (current_count <= 0)
    {
LABEL_4:
        if (current_count < 10)
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
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return found;
}
}
