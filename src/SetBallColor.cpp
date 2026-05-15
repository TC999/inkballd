#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    void __stdcall SetBallColor(CBall* ball, int color)
    {
        char* BitmapRect;
        int log_state = 0;

        auto ball_layout = reinterpret_cast<CBallLayout*>(ball);
        ball_layout->field_44 = color;
        
        BitmapRect = CGameBoard::GetBitmapRect(g_pCGameBoard, color + 2);
        log_state = -1;
        
        ball_layout->field_30 = reinterpret_cast<uintptr_t>(BitmapRect);
    }
}

