#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    void* point_array;
}
void InitBallPoints_CBall(CBall* self)
{
    int BallPoint;
    uint32_t ball_data_offset;
    int max_dot_product = 0;
    int point_index = 1;
    BallPoint* point_array;
    double max_value;
    double current_dot_product;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::InitBallPoints", 0);
    ball_data_offset = self->ball_points_data_offset;
    max_dot_product = 0;
    point_index = 1;
    point_array = reinterpret_cast<BallPoint*>(*(reinterpret_cast<uint32_t*>(ball_data_offset) + 8));
    max_value = static_cast<double>(*(reinterpret_cast<int*>(*(reinterpret_cast<uint32_t*>(ball_data_offset) + 4))) * self->velocity_y +
                                     static_cast<double>(**(reinterpret_cast<int**>(ball_data_offset))) * self->velocity_x);

    do
    {
    void* point_array; // auto-declared
        current_dot_product = static_cast<double>(point_array[1].y) * self->velocity_y +
                              static_cast<double>(point_array[0].x) * self->velocity_x;
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
