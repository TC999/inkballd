#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
extern void* operator new(size_t size);
}

};

};

void __thiscall CBall::SetTallness(CBall *this, void* new_tallness)
{
    bool is_same_tallness;
    int size_difference;
    double offset_adjustment;
    int double_size_difference;
    double original_position_x;
    double original_position_y;
    BallPoints* new_ball_points;
    BallPoints* created_points;
    void** old_ball_points;
    uint8_t log_buffer[20];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::SetTallness", 0);
    size_difference = reinterpret_cast<int>(new_tallness) - reinterpret_cast<int>(this->ball_points_data);
    is_same_tallness = new_tallness == this->ball_points_data;
    flag = 0;
    
    if (!is_same_tallness)
    {
        offset_adjustment = static_cast<double>(size_difference);
        double_size_difference = 2 * size_difference;
        original_position_x = this->position_x;
        this->width += double_size_difference;
        this->height += double_size_difference;
        this->position_x = original_position_x - offset_adjustment;
        this->position_y = this->position_y - offset_adjustment;
        CBall::CheckBoardBounds(this);
        this->ball_points_data = new_tallness;
        
        flag = 1;
        new_ball_points = reinterpret_cast<BallPoints*>(operator new(4));
        flag = 2;
        if (new_ball_points)
            created_points = BallPoints::BallPoints(new_ball_points, this->width);
        else
            created_points = nullptr;
            
        old_ball_points = reinterpret_cast<void**>(this->ball_points_ptr);
        flag = 1;
        if (old_ball_points)
        {
            BallPoints::scalar_deleting_destructor(old_ball_points, 1);
            this->ball_points_ptr = nullptr;
        }
        this->ball_points_ptr = created_points;
    }
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}

#endif
