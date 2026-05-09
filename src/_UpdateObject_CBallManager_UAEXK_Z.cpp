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

void __thiscall CBallManager::UpdateObject(CBallManager *this, uint32_t delta_time)
{
    bool should_update;
    uint32_t time_remaining;
    CBall* ball;
    uint32_t next_ball_index;
    CBoardTile* random_ball_launcher;
    uint8_t log_buffer[16];
    int flag;
    uint32_t current_spawn_timer;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBallManager::UpdateObject", 0);
    should_update = this->update_flags == 0;
    flag = 0;
    
    if (!should_update)
    {
        CBallManager::UpdateBallList(this);
        CBallManager::InitBallPositions(this);
        this->update_flags = 0;
    }
    
    if (this->ball_count <= 0)
        goto LABEL_12;
    
    CBallManager::UpdateBallPositions(this, delta_time);
    this->next_ball_timer -= delta_time;
    time_remaining = this->next_ball_timer;
    
    if (time_remaining <= 800)
    {
        this->spawn_timer += delta_time;
        if (this->spawn_timer >= 100)
        {
            bool was_hidden = this->spawn_delay == 0;
            this->spawn_timer = 0;
            this->spawn_delay = was_hidden;
        }
    }
    
    if (time_remaining <= 0 && this->generator_count > 0)
    {
        random_ball_launcher = CBallManager::GetRandomBallLauncher(this);
        if (BallOnTile(random_ball_launcher))
        {
            this->next_ball_timer = 0;
            goto LABEL_13;
        }
        
        next_ball_index = this->ball_start_index;
        this->ball_start_index = next_ball_index + 1;
        ball = GetBall(next_ball_index);
        CBallManager::SetBallOnLauncher(this, ball, random_ball_launcher);
        CBallManager::SetBallSpeed(this, ball, -1.0);
        reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ball) + 160)[0] = 1; // offset 0xA0 (40 * 4)
        reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ball) + 156)[0] = 1; // offset 0x9C (39 * 4)
        
        uint32_t spawn_interval = this->active_ball_count;
        --this->ball_count;
        this->spawn_delay = 0;
        this->next_ball_timer = spawn_interval;
        CBallManager::UpdateBallList(this);
        
        if (!this->timer_started)
        {
            this->timer_started = 1;
LABEL_12:
            StartTimer();
        }
    }
    
LABEL_13:
    (reinterpret_cast<void(__thiscall*)(CBallManager*)>(this->update_function))(this);
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
