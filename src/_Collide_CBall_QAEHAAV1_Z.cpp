#include <cstdint>
#include <cmath>
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

struct CBall {
    double position_x; // offset 0x10 (1 * 8)
    double position_y; // offset 0x18 (2 * 8)
    double velocity_x; // offset 0x20 (8 * 8)
    double velocity_y; // offset 0x28 (9 * 8)
    double mass; // offset 0x38 (7 * 8)
    uint32_t radius; // offset 0x18 (6 * 4)
    uint32_t collision_flags; // offset 0xA4 (41 * 4)
    // ... other members
};

int __thiscall CBall::Collide(CBall *this, CBall *other_ball)
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
    uint8_t log_buffer[8];
    double temp_x;
    double temp_y;
    int flag;

    collision_occurred = 0;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::Collide", 0);
    flag = 0;
    if (!CBall::BallsIntersect(this, other_ball))
        goto LABEL_4;
    
    collision_occurred = 1;
    if (CBall::MovingTowards(this, other_ball))
    {
        this_radius_half = static_cast<double>(this->radius) * 0.5;
        other_radius_half = static_cast<double>(other_ball->radius) * 0.5;
        this_center_x = this->position_x + this_radius_half;
        this_center_y = this_radius_half + this->position_y;
        other_center_x = other_ball->position_x + other_radius_half;
        other_center_y = other_radius_half + other_ball->position_y;
        
        distance_x = this_center_x - other_center_x;
        distance_y = this_center_y - other_center_y;
        distance_magnitude = sqrt(distance_y * distance_y + distance_x * distance_x);
        normal_x = distance_x / distance_magnitude;
        normal_y = distance_y / distance_magnitude;
        
        relative_velocity_x = normal_y * this->velocity_y + normal_x * this->velocity_x -
                             (other_ball->velocity_y * normal_y + other_ball->velocity_x * normal_x);
        impulse_magnitude = (relative_velocity_x + relative_velocity_x) / (this->mass + other_ball->mass);
        
        this->velocity_x = this->velocity_x - other_ball->mass * impulse_magnitude * normal_x;
        this->velocity_y = this->velocity_y - other_ball->mass * impulse_magnitude * normal_y;
        other_ball->velocity_x = normal_x * (impulse_magnitude * this->mass) + other_ball->velocity_x;
        other_ball->velocity_y = normal_y * (impulse_magnitude * this->mass) + other_ball->velocity_y;
        
LABEL_4:
        this->collision_flags = other_ball->collision_flags + 42;
        other_ball->collision_flags = this->collision_flags + 42;
    }
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return collision_occurred;
}
