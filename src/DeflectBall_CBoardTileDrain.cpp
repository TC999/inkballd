#include "global_types.h"
#include <cstdint>
#include <cmath>
#include <windows.h>

void DeflectBall_CBoardTileDrain(CBoardTileDrain* self, CBall* ball)
{
    uint32_t direction;
    LONG right_edge;
    LONG bottom_edge;
    uint32_t ball_tile_type;
    uint32_t new_bitmap_index;
    void* bitmap_rect;
    double ball_radius;
    double new_distance;
    double current_distance;
    uint32_t drain_tile_type;
    uint32_t ball_drain_type;
    int collision_result;
    RECT bounding_rect;
    POINT ball_center;
    LONG drain_x;
    LONG drain_y;
    int distance_y;
    int distance_x;
    uint8_t log_buffer[8];
    long double distance_squared;
    long double force_multiplier;
    long double new_velocity_x;
    long double new_velocity_y;

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)&log_buffer, "CBoardTileDrain::DeflectBall", 0);
    
    CBoardObject::GetBoundingRect(self, &bounding_rect);
    direction = *(uint32_t*)((uint8_t*)self + 124); // drain_direction
    
    if (direction == 2 || (right_edge = bounding_rect.left, direction == 4))
        right_edge = bounding_rect.right;
    drain_x = right_edge;
    
    if (direction == 2 || (bottom_edge = bounding_rect.top, direction == 3))
        bottom_edge = bounding_rect.bottom;
    drain_y = bottom_edge;
    
    CBoardObject::GetCenterPoint(ball, &ball_center);
    distance_y = ball_center.y - bottom_edge;
    distance_x = ball_center.x - drain_x;
    current_distance = sqrt(static_cast<double>((ball_center.x - drain_x) * (ball_center.x - drain_x) + 
                                                 (ball_center.y - bottom_edge) * (ball_center.y - bottom_edge)));
    
    ball_tile_type = ((uint32_t*)ball)[1]; // ball->tile_type
    if (current_distance > 42.0)
        new_bitmap_index = ball_tile_type + 2;
    else
        new_bitmap_index = ball_tile_type + 7;
    
    bitmap_rect = CBitmapRects::GetBitmapRect(g_CBitmapRects, new_bitmap_index);
    ball_radius = static_cast<double>(ball->radius);
    reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(ball) + 32)[0] = (uint32_t)(uintptr_t)bitmap_rect;
    new_distance = ball_radius * 0.5 + current_distance;
    
    if (new_distance > 12.0)
    {
        if (current_distance <= 32.0)
        {
            distance_squared = 1.0 / (current_distance * current_distance);
            new_velocity_x = ball->velocity_x * 0.993 - static_cast<double>(distance_x) * distance_squared * 25.0;
            new_velocity_y = 0.993 * ball->velocity_y - 25.0 * (distance_squared * static_cast<double>(distance_y));
            CBall::SetTallness(ball, (int)(0.0 - 3.0 / current_distance * 8.0));
        }
    }
    else
    {
        drain_tile_type = ((uint32_t*)self)[1]; // self->tile_type
        ball_drain_type = ((uint32_t*)ball)[1]; // ball->tile_type
        if (drain_tile_type != ball_drain_type && drain_tile_type && ball_drain_type)
        {
            KillPlayer(1);
        }
        else
        {
            ScoreBall(ball, ((uint32_t*)self)[1]); // self->tile_type
            ball->update_flags = 0;
            collision_result = ((uint32_t*)self)[1]; // self->tile_type
            if (collision_result && ((uint32_t*)ball)[1]) // ball->tile_type
                ToggleRLWalls(collision_result);
        }
    }
    
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}
