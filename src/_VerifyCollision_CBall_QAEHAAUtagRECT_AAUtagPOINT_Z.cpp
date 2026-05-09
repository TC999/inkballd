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
    extern BOOL PointInRect(LONG x, LONG y, const RECT* rect);
}

};

};

int __thiscall CBall::VerifyCollision(CBall *this, RECT* collision_rect, POINT* collision_point)
{
    int point_index = 0;
    BallPoint* current_point;
    int collision_found = 0;
    LONG point_x;
    LONG point_y;
    uint8_t log_buffer[8];
    POINT center_point;
    int flag;

    point_index = 0;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBall::VerifyCollision", 0);
    flag = 0;
    CBoardObject::GetCenterPoint(this, &center_point);
    if (this->point_count <= 0)
    {
LABEL_4:
        collision_found = 0;
    }
    else
    {
        while (true)
        {
            current_point = CBall::GetPoint(this, point_index);
            collision_point->x = center_point.x + current_point->x;
            point_y = center_point.y + current_point->y;
            point_x = collision_point->x;
            collision_point->y = point_y;
            if (PointInRect(point_x, point_y, collision_rect))
                break;
            if (++point_index >= this->point_count)
                goto LABEL_4;
        }
        collision_found = 1;
    }
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return collision_found;
}
