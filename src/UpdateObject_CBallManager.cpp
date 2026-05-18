#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

void UpdateObject_CBallManager(CBallManager *self, uint32_t delta_time)
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
    should_update = self->update_flags == 0;
    flag = 0;
    
    if (!should_update)
    {
        CBallManager::UpdateBallList(self);
        CBallManager::InitBallPositions(self);
        self->update_flags = 0;
    }
    
    if (self->ball_count <= 0)
    {
        if (!self->timer_started)
        {
            self->timer_started = 1;
            StartTimer();
        }
        goto LABEL_13;
    }
    
    CBallManager::UpdateBallPositions(self, delta_time);
    self->next_ball_timer -= delta_time;
    time_remaining = self->next_ball_timer;
    
    if (time_remaining <= 800)
    {
        self->spawn_timer += delta_time;
        if (self->spawn_timer >= 100)
        {
            bool was_hidden = self->spawn_delay == 0;
            self->spawn_timer = 0;
            self->spawn_delay = was_hidden;
        }
    }
    
    if (time_remaining <= 0 && self->generator_count > 0)
    {
        random_ball_launcher = CBallManager::GetRandomBallLauncher(self);
        if (BallOnTile(random_ball_launcher))
        {
            self->next_ball_timer = 0;
            goto LABEL_13;
        }
        
        next_ball_index = self->ball_start_index;
        self->ball_start_index = next_ball_index + 1;
        ball = GetBall(next_ball_index);
        CBallManager::SetBallOnLauncher(self, ball, random_ball_launcher);
        CBallManager::SetBallSpeed(self, ball, -1.0);
        reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ball) + 160)[0] = 1; // offset 0xA0 (40 * 4)
        reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ball) + 156)[0] = 1; // offset 0x9C (39 * 4)
        
        uint32_t spawn_interval = self->active_ball_count;
        --self->ball_count;
        self->spawn_delay = 0;
        self->next_ball_timer = spawn_interval;
        CBallManager::UpdateBallList(self);
        
        if (!self->timer_started)
        {
            self->timer_started = 1;
            StartTimer();
        }
    }
    
LABEL_13:
    CBallManager::DrawToSurface(self);
    flag = -1;
    ((Helpers::CLogBlock *)&log_buffer)->~CLogBlock();
}
