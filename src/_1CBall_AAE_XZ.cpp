#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

};

extern "C" void* CBall_vftable; // Forward declaration of virtual table

CBall::~CBall(CBall *this)
{
    void** ball_points_data;
    uint8_t log_buffer[16];
    int flag;

    this->vftable = &CBall_vftable;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::~CBall", 0);
    ball_points_data = reinterpret_cast<void**>(this->ball_points_ptr);
    flag = 0;
    if (ball_points_data)
    {
        BallPoints::scalar_deleting_destructor(ball_points_data, 1);
        this->ball_points_ptr = nullptr;
    }
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}

#endif
