#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
typedef int (__stdcall *CollisionCheckFunc)(const RECT*);
}

int Collide_CBall(CBall *self, CollisionCheckFunc collision_check)
{
    int BallPoint;
    int last_collision_point = -1;
    int first_collision_point = -1;
    BallPoint* next_point;
    int prev_ball_point;
    int collision_index;
    int* point_data;
    int collision_occurred = 0;
    RECT collision_rect;
    POINT center_point;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)log_buffer, "CBall::Collide", 0);
    flag = 0;
    CBall::InitBallPoints(self);
    collision_occurred = 0;
    last_collision_point = -1;
    first_collision_point = -1;
    CBoardObject::GetCenterPoint(self, &center_point);
    next_point = CBall::GetNextPoint(self);
    if (!next_point)
        goto LABEL_12;
    
    do
    {
        collision_rect.left = center_point.x + next_point->x;
        collision_rect.right = center_point.x + next_point->x;
        collision_rect.top = center_point.y + next_point->y;
        collision_rect.bottom = center_point.y + next_point->y;
        
        if (collision_check(&collision_rect))
        {
            prev_ball_point = CBall::GetPrevBallPoint(self);
            if (first_collision_point == -1)
                first_collision_point = prev_ball_point;
            last_collision_point = prev_ball_point;
            collision_occurred = 1;
        }
        next_point = CBall::GetNextPoint(self);
    }
    while (next_point);
    
    if (collision_occurred)
    {
        collision_index = (last_collision_point + first_collision_point) / 2;
        if (last_collision_point < first_collision_point)
            collision_index = (collision_index + 16) % 32;
        point_data = reinterpret_cast<int*>(CBall::GetPoint(self, collision_index));
        CBall::Deflect(self, static_cast<double>(point_data[0]), static_cast<double>(point_data[1]));
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
