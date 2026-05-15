#include "global_types.h"
#include <cstdint>
#include <windows.h>

struct BallPoint { int x; int y; };
void InitBallPoints_CBall(CBall* self)
{
    int dot_product_saved;
    uint32_t ball_data_offset;
    int max_dot_product = 0;
    int point_index = 1;
    BallPoint* point_array;
    double max_value;
    double current_dot_product;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::InitBallPoints", 0);
    ball_data_offset = *(uint32_t*)((char*)self + 120);
    max_dot_product = 0;
    point_index = 1;
    point_array = reinterpret_cast<BallPoint*>((char*)(ball_data_offset) + 8);
    max_value = (double)*(int*)(ball_data_offset + 4) * self->velocity_y +
                (double)(**(int**)(ball_data_offset)) * self->velocity_x;

    do
    {
        current_dot_product = (double)point_array[1].y * self->velocity_y +
                              (double)point_array[0].x * self->velocity_x;
        if (current_dot_product > max_value)
        {
            max_dot_product = point_index;
            max_value = current_dot_product;
        }
        ++point_index;
        point_array += 2;
    }
    while (point_index < 32);

    self->best_point_index = max_dot_product - 8;
    if (max_dot_product - 8 < 0)
        self->best_point_index = max_dot_product - 8 + 32;
    self->current_point_index = 0;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
