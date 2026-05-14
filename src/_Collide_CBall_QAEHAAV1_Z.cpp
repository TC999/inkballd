#include "global_types.h"
#include <cstdint>
#include <cmath>
#include <windows.h>

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
