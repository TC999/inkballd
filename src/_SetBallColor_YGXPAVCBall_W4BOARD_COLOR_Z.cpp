#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

class Helpers {
public:
    class CLogBlock {
    public:
        CLogBlock(void* buffer, const char* message, int* error_code);
        ~CLogBlock();
    };
};

class CGameBoard;
class CBall;

};

extern "C" {
    void __stdcall SetBallColor(CBall* ball, int color)
    {
        char* BitmapRect;
        uint8_t log_buffer[16];
        int log_state = 0;

        Helpers::CLogBlock log_block(log_buffer, "SetBallColor", nullptr);
        
        auto ball_layout = reinterpret_cast<CBallLayout*>(ball);
        ball_layout->field_44 = color;
        
        BitmapRect = CGameBoard::GetBitmapRect(color + 2);
        log_state = -1;
        
        ball_layout->field_30 = BitmapRect;
    }
}

#endif
