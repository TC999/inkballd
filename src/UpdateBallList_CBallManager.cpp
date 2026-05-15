#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

void UpdateBallList_CBallManager(CBallManager *self)
{
    int old_active_count;
    uint32_t* ball_list_ptr;
    uint32_t current_ball_data;
    bool iteration_complete;
    uint32_t current_ball_index;
    int* ball_indices_ptr;
    CBall* current_ball;
    uint32_t ball_update_flag;
    uint32_t ball_index_value;
    uint32_t list_index;
    uint32_t max_balls = 5;
    uint8_t log_buffer[8];
    int flag;
    int active_count;
    int max_balls_count;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::UpdateBallList", 0);
    flag = 0;
    active_count = 0;
    old_active_count = self->active_ball_count;
    ball_list_ptr = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(self) + 56);
    max_balls_count = 5;
    
    do
    {
        current_ball_data = ball_list_ptr[1];
        ball_list_ptr[0] = current_ball_data;
        reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(current_ball_data) + 156)[0] = 0;
        iteration_complete = max_balls_count-- == 1;
        ++ball_list_ptr;
    }
    while (!iteration_complete);
    
    self->active_ball_count = old_active_count;
    reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(old_active_count) + 156)[0] = 0;
    
    current_ball_index = self->ball_start_index;
    if (current_ball_index < current_ball_index + self->ball_count)
    {
        ball_indices_ptr = reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(self) + 56);
        do
        {
            current_ball = GetBall(current_ball_index);
            list_index = ball_indices_ptr[0];
            ball_update_flag = reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(current_ball) + 11)[0];
            ++active_count;
            reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(list_index) + 44)[0] = ball_update_flag;
            ball_index_value = ball_indices_ptr[0]++;
            bool within_limit = active_count <= 5;
            reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ball_index_value) + 156)[0] = 1;
            if (!within_limit)
                break;
            ++current_ball_index;
        }
        while (current_ball_index < self->ball_count + self->ball_start_index);
    }
    
    flag = -1;
    ((Helpers::CLogBlock *)&log_buffer)->~CLogBlock();
}
