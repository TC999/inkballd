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
    extern double cosd(double angle);
    extern double sind(double angle);
    extern int GetRandomNumber(int max_value);
}

struct CBall {
    double velocity_x; // offset 0x20 (8 * 8)
    double velocity_y; // offset 0x28 (9 * 8)
    // ... other members
};

struct CBallManager {
    uint32_t min_speed; // offset 0x144 (324 * 4)
    uint32_t max_speed; // offset 0x148 (325 * 4)
    // ... other members
};

void __thiscall CBallManager::SetBallSpeed(CBallManager *this, CBall* ball, double angle_degrees)
{
    int max_speed_value;
    int min_speed_value;
    double speed_magnitude;
    CBall* target_ball;
    double velocity_x;
    double velocity_y;
    double cos_angle;
    double sin_angle;
    uint8_t log_buffer[8];
    int flag;
    double adjusted_angle;
    double final_velocity_x;
    double final_velocity_y;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::SetBallSpeed", 0);
    max_speed_value = this->max_speed;
    min_speed_value = this->min_speed;
    flag = 0;
    
    if (max_speed_value != min_speed_value)
        speed_magnitude = static_cast<double>(min_speed_value + GetRandomNumber(max_speed_value - min_speed_value));
    else
        speed_magnitude = static_cast<double>(max_speed_value);
    
    adjusted_angle = angle_degrees;
    if (angle_degrees != -1.0)
    {
        if (angle_degrees == 0.0)
            adjusted_angle = 360.0;
        
        if (adjusted_angle <= 90.0)
        {
            double angle_diff = 90.0 - adjusted_angle;
            target_ball = ball;
            ball->velocity_x = cosd(angle_diff) * speed_magnitude;
            sin_angle = sind(angle_diff);
            goto LABEL_18;
        }
        
        if (adjusted_angle > 180.0)
        {
            if (adjusted_angle > 270.0)
            {
                double angle_diff = 360.0 - adjusted_angle;
                target_ball = ball;
                ball->velocity_x = -(sind(angle_diff) * speed_magnitude);
                cos_angle = cosd(angle_diff);
                goto LABEL_18;
            }
            double angle_diff = 270.0 - adjusted_angle;
            target_ball = ball;
            ball->velocity_x = -(cosd(angle_diff) * speed_magnitude);
            sin_angle = sind(angle_diff);
        }
        else
        {
            double angle_diff = 180.0 - adjusted_angle;
            target_ball = ball;
            ball->velocity_x = sind(angle_diff) * speed_magnitude;
            cos_angle = cosd(angle_diff);
        }
        
        velocity_y = cos_angle * speed_magnitude;
        goto LABEL_20;
    }
    
    target_ball = ball;
    velocity_x = (static_cast<double>(GetRandomNumber(100)) / 100.0) * speed_magnitude;
    ball->velocity_x = velocity_x;
    ball->velocity_y = sqrt(speed_magnitude * speed_magnitude - velocity_x * velocity_x);
    
    if (GetRandomNumber(2))
        ball->velocity_x = -ball->velocity_x;
    
    if (GetRandomNumber(2))
    {
        velocity_y = ball->velocity_y;
        goto LABEL_19;
    }
    
LABEL_21:
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return;

LABEL_18:
    velocity_y = sin_angle * speed_magnitude;
LABEL_19:
    final_velocity_y = -velocity_y;
LABEL_20:
    target_ball->velocity_y = final_velocity_y;
    goto LABEL_21;
}
