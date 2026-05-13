#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

void UpdateObject_CBall(CBall *this, uint32_t delta_time)
{
    bool should_update;
    double time_factor;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::UpdateObject", 0);
    should_update = this->update_flags == 0;
    flag = 0;
    if (!should_update)
    {
        time_factor = static_cast<double>(delta_time) / 1000.0;
        this->old_position_x = this->position_x;
        this->old_position_y = this->position_y;
        this->position_x = this->velocity_x * time_factor + this->position_x;
        this->position_y = time_factor * this->velocity_y + this->position_y;
        if (!CBall::CheckBoardBounds(this))
        {
            CBall::AddRef(this);
            CheckForBallCollisionWithNonDeflectingTile(this);
            if (static_cast<int>(this->position_x) != static_cast<int>(this->old_position_x) ||
                static_cast<int>(this->position_y) != static_cast<int>(this->old_position_y))
            {
                CheckForBallCollisionWithBall(this);
                CheckForBallCollisionWithInk(this);
                CheckForBallCollisionWithTile(this);
            }
            CBall::Release(this);
        }
    }
    flag = -1;
    ((Helpers::CLogBlock *)&log_buffer)->~CLogBlock();
}
