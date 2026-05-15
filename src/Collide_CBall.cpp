#include "global_types.h"
#include <cstdint>
#include <cmath>
#include <windows.h>

struct BallPoint { int x; int y; };

extern "C" {
    typedef int(__stdcall* CollisionCheckFunc)(const POINT*, const CBall*);
}

int Collide_CBall(CBall* self, CollisionCheckFunc collision_check)
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
    CBall::InitBallPoints(self);
    collision_occurred = 0;
    last_collision_point = -1;
    first_collision_point = -1;
    CBoardObject::GetCenterPoint(self, &center_point);
    next_point = (BallPoint*)CBall::GetNextPoint(self);
    if (!next_point)
        goto LABEL_12;

    do
    {
        collision_point.x = center_point.x + next_point->x;
        collision_point.y = center_point.y + next_point->y;

        if (collision_check(&collision_point, self))
        {
            prev_ball_point = (int)(intptr_t)CBall::GetPrevBallPoint(self);
            if (first_collision_point == -1)
                first_collision_point = prev_ball_point;
            last_collision_point = prev_ball_point;
            collision_occurred = 1;
        }
        next_point = (BallPoint*)CBall::GetNextPoint(self);
    } while (next_point);

    if (collision_occurred)
    {
        collision_index = (last_collision_point + first_collision_point) / 2;
        if (last_collision_point < first_collision_point)
            collision_index = (collision_index + 16) % 32;
        point_data = reinterpret_cast<int*>(CBall::GetPoint(self, collision_index));
        CBall::Deflect(self, (double)point_data[0], (double)point_data[1]);
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

int Collide_CBall(CBall* self, void* collision_check)
{
    int last_collision_point = -1;
    int first_collision_point = -1;
    BallPoint* next_point;
    int prev_ball_point;
    int collision_index;
    int collision_occurred = 0;
    RECT collision_rect;
    POINT center_point;
    uint8_t log_buffer[16];
    int flag;

    typedef int(__stdcall* CollisionCheckFunc)(const RECT*);
    CollisionCheckFunc check_func = (CollisionCheckFunc)collision_check;

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)log_buffer, "CBall::Collide", 0);
    flag = 0;
    CBall::InitBallPoints(self);
    collision_occurred = 0;
    last_collision_point = -1;
    first_collision_point = -1;
    CBoardObject::GetCenterPoint(self, &center_point);
    next_point = (BallPoint*)CBall::GetNextPoint(self);
    if (!next_point)
        goto LABEL_12;

    do
    {
        collision_rect.left = center_point.x + next_point->x;
        collision_rect.right = center_point.x + next_point->x;
        collision_rect.top = center_point.y + next_point->y;
        collision_rect.bottom = center_point.y + next_point->y;

        if (check_func(&collision_rect))
        {
            prev_ball_point = CBall::GetPrevBallPoint(self);
            if (first_collision_point == -1)
                first_collision_point = prev_ball_point;
            last_collision_point = prev_ball_point;
            collision_occurred = 1;
        }
        next_point = (BallPoint*)CBall::GetNextPoint(self);
    } while (next_point);

    if (collision_occurred)
    {
        collision_index = (last_collision_point + first_collision_point) / 2;
        if (last_collision_point < first_collision_point)
            collision_index = (collision_index + 16) % 32;
        BallPoint* point_data = (BallPoint*)CBall::GetPoint(self, collision_index);
        CBall::Deflect(self, (double)point_data->x, (double)point_data->y);
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


int Collide_CBall(CBall *self, CBall *other_ball)
{
    int collision_occurred = 0;
    double this_radius_half;
    double other_radius_half;
    double this_center_x;
    double this_center_y;
    double other_center_x;
    double other_center_y;
    double distance_x;
    double distance_y;
    double distance_magnitude;
    double normal_x;
    double normal_y;
    double relative_velocity_x;
    double relative_velocity_y;
    double impulse_magnitude;
    double impulse_x;
    double impulse_y;
    uint8_t log_buffer[16];
    double temp_x;
    double temp_y;
    int flag;

    collision_occurred = 0;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)log_buffer, "CBall::Collide", 0);
    flag = 0;
    if (!CBall::BallsIntersect(self, other_ball))
        goto LABEL_4;
    
    collision_occurred = 1;
    if (CBall::MovingTowards(self, other_ball))
    {
        this_radius_half = static_cast<double>(self->radius) * 0.5;
        other_radius_half = static_cast<double>(other_ball->radius) * 0.5;
        this_center_x = self->position_x + this_radius_half;
        this_center_y = this_radius_half + self->position_y;
        other_center_x = other_ball->position_x + other_radius_half;
        other_center_y = other_radius_half + other_ball->position_y;
        
        distance_x = this_center_x - other_center_x;
        distance_y = this_center_y - other_center_y;
        distance_magnitude = sqrt(distance_y * distance_y + distance_x * distance_x);
        normal_x = distance_x / distance_magnitude;
        normal_y = distance_y / distance_magnitude;
        
        relative_velocity_x = normal_y * self->velocity_y + normal_x * self->velocity_x -
                             (other_ball->velocity_y * normal_y + other_ball->velocity_x * normal_x);
        impulse_magnitude = (relative_velocity_x + relative_velocity_x) / (self->mass + other_ball->mass);
        
        self->velocity_x = self->velocity_x - other_ball->mass * impulse_magnitude * normal_x;
        self->velocity_y = self->velocity_y - other_ball->mass * impulse_magnitude * normal_y;
        other_ball->velocity_x = normal_x * (impulse_magnitude *self->mass) + other_ball->velocity_x;
        other_ball->velocity_y = normal_y * (impulse_magnitude *self->mass) + other_ball->velocity_y;
        
        self->collision_flags = other_ball->collision_flags + 42;
        other_ball->collision_flags = self->collision_flags + 42;
    }
    else
    {
LABEL_4:
        self->collision_flags = other_ball->collision_flags + 42;
        other_ball->collision_flags = self->collision_flags + 42;
    }
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return collision_occurred;
}
