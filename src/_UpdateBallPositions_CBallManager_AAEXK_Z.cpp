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

};

void __thiscall CBallManager::UpdateBallPositions(CBallManager *this, uint32_t delta_time)
{
    double time_factor;
    uint32_t active_ball_offset;
    double accumulator_offset;
    uint8_t* ball_ptr;
    uint32_t current_ball;
    int ball_index;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::UpdateBallPositions", 0);
    time_factor = static_cast<double>(delta_time) / 1000.0;
    active_ball_offset = this->active_ball_count;
    
    CBall* first_ball = reinterpret_cast<CBall*>(active_ball_offset);
    if (first_ball->position_x > 6.0)
    {
        accumulator_offset = 0.0;
        first_ball->accumulator_x = first_ball->accumulator_x - 6.0;
        first_ball->position_x = first_ball->accumulator_x * time_factor + first_ball->position_x;
        first_ball->position_y = first_ball->accumulator_y * time_factor + first_ball->position_y;
    }
    else
    {
        first_ball->accumulator_x = 0.0;
        accumulator_offset = 0.0;
        first_ball->position_x = 6.0;
    }
    
    ball_ptr = reinterpret_cast<uint8_t*>(this) + 60;
    for (ball_index = 5; ball_index > 0; --ball_index)
    {
        current_ball = *reinterpret_cast<uint32_t*>(ball_ptr);
        CBall* current_ball_ptr = reinterpret_cast<CBall*>(current_ball);
        uint32_t launcher_offset = *reinterpret_cast<uint32_t*>(ball_ptr - 4);
        CBall* launcher_ball = reinterpret_cast<CBall*>(launcher_offset);
        
        double launcher_position = static_cast<double>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(launcher_ball) + 24)) +
                                   launcher_ball->position_x + accumulator_offset;
        
        if (launcher_position < current_ball_ptr->position_x)
        {
            current_ball_ptr->accumulator_x = current_ball_ptr->accumulator_x - static_cast<double>(ball_index);
            current_ball_ptr->position_x = current_ball_ptr->accumulator_x * time_factor + current_ball_ptr->position_x;
            current_ball_ptr->position_y = current_ball_ptr->accumulator_y * time_factor + current_ball_ptr->position_y;
        }
        else
        {
            current_ball_ptr->accumulator_x = accumulator_offset;
            current_ball_ptr->position_x = static_cast<double>(*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(launcher_ball) + 24)) +
                                           launcher_ball->position_x + accumulator_offset;
        }
        ball_ptr += 4;
    }
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
