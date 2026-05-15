#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void* CBallManager_vftable; // Forward declaration of virtual table

CBallManager::~CBallManager()
{
    CBall** ball_ptr;
    int ball_count;
    uint8_t log_buffer[16];
    int flag;

    *((uint32_t*)self + 0) = reinterpret_cast<uint32_t>(&CBallManager_vftable);
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBallManager::~CBallManager", 0);
    flag = 0;
    
    ball_ptr = reinterpret_cast<CBall**>(reinterpret_cast<uint8_t*>(self) + 56);
    ball_count = 6;
    
    do
    {
        if (*ball_ptr)
        {
            CBall::Release(*ball_ptr);
            *ball_ptr = nullptr;
        }
        ++ball_ptr;
        --ball_count;
    }
    while (ball_count);
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
