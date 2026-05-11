#if 0
#include "global_types.h"
#include <cstdint>
#include <new>
#include <cstddef>



extern "C" {
    void AddBallToUpdateList(CBall* ball);
}

extern "C" {
    int CBall_func(int this_ptr, int rect_x, int rect_y, int should_add, int ball_radius)
    {\r\n        void* ball_points_mem; // ecx
        BallPoints* ball_points; // eax
        int i; // eax
        uint8_t log_buffer[8]; // [esp+10h] [ebp-1Ch] BYREF
        void* temp_ptr; // [esp+18h] [ebp-14h]
        int log_state; // [esp+28h] [ebp-4h]

        new (reinterpret_cast<CMovingObject*>(this_ptr)) CMovingObject(reinterpret_cast<CMovingObject*>(this_ptr));
        auto layout = reinterpret_cast<CBallLayout*>(this_ptr);
        layout->vftable_ptr = 0;
        
        new (log_buffer) Helpers::CLogBlock(log_buffer, "CBall::CBall", 0);
        log_state = 0;
        layout->field_136 = 0;
        log_state = 1;
        ball_points_mem = operator new(4u);
        temp_ptr = ball_points_mem;
        log_state = 2;
        if (ball_points_mem) {
            new (ball_points_mem) BallPoints();
            ball_points = reinterpret_cast<BallPoints*>(ball_points_mem);
        } else {
            ball_points = nullptr;
        }
        layout->field_124 = static_cast<uint32_t>(-1);
        layout->field_120 = reinterpret_cast<uintptr_t>(ball_points);
        layout->field_144 = 1;
        layout->field_56 = 1;
        layout->field_44 = rect_y;
        layout->field_32 = rect_x;
        log_state = 0;
        layout->field_128 = 0;
        layout->field_132 = 32;
        layout->field_140 = 0;
        layout->field_152 = 0;
        layout->field_24 = ball_radius;
        layout->field_28 = ball_radius;
        layout->field_112 = ball_radius;
        layout->field_116 = ball_radius;
        layout->field_156 = 0;
        layout->field_160 = 0;
        for (i = 0; i < 64; ++i)
            layout->ball_points_array[i] = 0;
        if (should_add)
            AddBallToUpdateList(reinterpret_cast<CBall*>(this_ptr));
        log_state = -1;
        reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
        return this_ptr;
    }
}

#endif
