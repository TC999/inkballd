#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

void UpdateObject_CBall(CBall *self, uint32_t delta_time)
{
    bool should_update;
    double time_factor;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::UpdateObject", 0);
    should_update = self->update_flags == 0;
    flag = 0;
    if (!should_update)
    {
        time_factor = static_cast<double>(delta_time) / 1000.0;
        self->old_position_x = self->position_x;
        self->old_position_y = self->position_y;
        self->position_x = self->velocity_x * time_factor + self->position_x;
        self->position_y = time_factor * self->velocity_y + self->position_y;
        if (!CBall::CheckBoardBounds(self))
        {
            CBall::AddRef(self);
            CheckForBallCollisionWithNonDeflectingTile(self);
            if (static_cast<int>(self->position_x) != static_cast<int>(self->old_position_x) ||
                static_cast<int>(self->position_y) != static_cast<int>(self->old_position_y))
            {
                CheckForBallCollisionWithBall(self);
                CheckForBallCollisionWithInk(self);
                CheckForBallCollisionWithTile(self);
            }
            CBall::Release(self);
        }
    }
    flag = -1;
    ((Helpers::CLogBlock *)&log_buffer)->~CLogBlock();
}
