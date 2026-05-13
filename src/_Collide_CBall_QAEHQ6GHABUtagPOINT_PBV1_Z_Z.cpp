#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
typedef int (__stdcall *CollisionCheckFunc)(const POINT*, const CBall*);
}

int __thiscall CBall::Collide(CBall *this, CollisionCheckFunc collision_check)
{
    int last_collision_point = -1;
    int first_collision_point = -1;
    BallPoint* next_point;
    int prev_ball_point;
    int collision_index;
    int* point_data;
    int collision_occurred = 0;
    POINT collision_point;
    POINT center_point;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)log_buffer, "CBall::Collide", 0);
    flag = 0;
    CBall::InitBallPoints(this);
    collision_occurred = 0;
    last_collision_point = -1;
    first_collision_point = -1;
    CBoardObject::GetCenterPoint(this, &center_point);
    next_point = CBall::GetNextPoint(this);
    if (!next_point)
        goto LABEL_12;
    
    do
    {
        collision_point.x = center_point.x + next_point->x;
        collision_point.y = center_point.y + next_point->y;
        
        if (collision_check(&collision_point, this))
        {
            prev_ball_point = CBall::GetPrevBallPoint(this);
            if (first_collision_point == -1)
                first_collision_point = prev_ball_point;
            last_collision_point = prev_ball_point;
            collision_occurred = 1;
        }
        next_point = CBall::GetNextPoint(this);
    }
    while (next_point);
    
    if (collision_occurred)
    {
        collision_index = (last_collision_point + first_collision_point) / 2;
        if (last_collision_point < first_collision_point)
            collision_index = (collision_index + 16) % 32;
        point_data = reinterpret_cast<int*>(CBall::GetPoint(this, collision_index));
        CBall::Deflect(this, static_cast<double>(point_data[0]), static_cast<double>(point_data[1]));
        flag = 1;
    }
    else
    {
LABEL_12:
        flag = 0;
    }
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return flag;
}
