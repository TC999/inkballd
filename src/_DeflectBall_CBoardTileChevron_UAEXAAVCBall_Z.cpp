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

struct CBoardTileChevron {
    uint32_t chevron_direction; // offset 0x58 (22 * 4)
    // ... members
};

struct CBall {
    double velocity_x; // offset 0x20 (8 * 8)
    double velocity_y; // offset 0x28 (9 * 8)
    // ... members
};

void __thiscall CBoardTileChevron::DeflectBall(CBoardTileChevron *this, CBall* ball)
{
    uint32_t direction;
    double* velocity_ptr;
    long double new_velocity_x;
    double* velocity_ptr_y;
    long double new_velocity_y;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardTileChevron::DeflectBall", 0);
    direction = this->chevron_direction;
    flag = 0;
    
    if (direction)
    {
        if (direction != 1)
        {
            if (direction == 2)
            {
                velocity_ptr_y = &ball->velocity_x;
                new_velocity_y = ball->velocity_x - 3.0;
            }
            else
            {
                if (direction != 3)
                    goto LABEL_11;
                velocity_ptr_y = &ball->velocity_x;
                new_velocity_y = ball->velocity_x + 3.0;
            }
            velocity_ptr_y[0] = new_velocity_y;
            CBall::SetXVel(ball, new_velocity_y);
            goto LABEL_11;
        }
        velocity_ptr = &ball->velocity_y;
        new_velocity_x = ball->velocity_y + 3.0;
    }
    else
    {
        velocity_ptr = &ball->velocity_y;
        new_velocity_x = ball->velocity_y - 3.0;
    }
    velocity_ptr[0] = new_velocity_x;
    CBall::SetYVel(ball, new_velocity_x);
    
LABEL_11:
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
      else
      {
        if ( v3 != 3 )
          goto LABEL_11;
        v6 = (double *)a2;
        v7 = *((double *)a2 + 8) + 3.0;
      }
      v6[8] = v7;
      CBall::SetXVel((CBall *)v6, v7);
      goto LABEL_11;
    }
    v4 = (double *)a2;
    v5 = *((double *)a2 + 9) + 3.0;
  }
  else
  {
    v4 = (double *)a2;
    v5 = *((double *)a2 + 9) - 3.0;
  }
  v4[9] = v5;
  CBall::SetYVel((CBall *)v4, v5);
LABEL_11:
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
