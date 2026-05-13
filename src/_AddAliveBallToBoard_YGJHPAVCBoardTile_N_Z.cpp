#if 0
#include "global_types.h"
#include <cstdint>
#include <new>
#include <windows.h>

class Helpers {
public:
    class CLogBlock {
    public:
        CLogBlock(void* buffer, const char* message, int* error_code);
        ~CLogBlock();
};

extern "C" {
    int NumBallsOnBoard(void* game_board);
    void DisplayBoardLoadMsg();
    void GetCenterPoint(void* obj, void* point);
    char* GetBitmapRect(int rect_id);
    int CBall_ctor(int a1, int a2, int a3, int a4, int a5);
    void AddRef(void* ball);
    void SetBallSpeed(void* mgr, void* ball, double speed);
    void AddBall(void* game_board, void* ball);
}
extern "C" {
    extern void* g_pCGameBoard;
    
    int __stdcall AddAliveBallToBoard(int ball_type, void* tile, double speed)
    {
        char* bitmap_rect;
        int ball_result;
        POINT center_point;
        uint8_t log_buffer[8];
        int error_code[4] = {0};
        int init_step = 0;
        void* ball_object = nullptr;

        new (log_buffer) Helpers::CLogBlock(log_buffer, "AddAliveBallToBoard", error_code);
        
        if (NumBallsOnBoard(g_pCGameBoard) >= 64) {
            DisplayBoardLoadMsg();
        }
        
        GetCenterPoint(tile, &center_point);
        init_step = 1;
        
        ball_object = operator new(0x1A8u);
        init_step = 2;
        
        if (ball_object)
        {
            bitmap_rect = GetBitmapRect(ball_type + 2);
            ball_result = CBall_ctor(reinterpret_cast<int>(ball_object), 
                                     reinterpret_cast<int>(bitmap_rect), 
                                     ball_type, 1, 
                                     *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471));
        }
        else
        {
            ball_result = 0;
        }
        
        init_step = 0;
        if (ball_result)
        {
            AddRef(reinterpret_cast<void*>(ball_result));
            
            auto ball_layout = reinterpret_cast<CBallLayout*>(ball_result);
            ball_layout->field_24 = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471);
            ball_layout->field_28 = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471);
            ball_layout->field_C = static_cast<double>(center_point.x) - static_cast<double>(*reinterpret_cast<int*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471)) * 0.5;
            ball_layout->field_10 = static_cast<double>(center_point.y) - 0.5 * static_cast<double>(*reinterpret_cast<int*>(reinterpret_cast<char*>(g_pCGameBoard) + 2471));
            
            SetBallSpeed(*reinterpret_cast<void**>(reinterpret_cast<char*>(g_pCGameBoard) + 2476), 
                                     reinterpret_cast<void*>(ball_result), 
                                     speed);
            
            ball_layout->field_154 = 1;
            ball_layout->field_158 = 1;
            
            AddBall(g_pCGameBoard, reinterpret_cast<void*>(ball_result));
            
            init_step = -1;
            error_code[0] = 0;
            return 0;
        }
        else
        {
            init_step = -1;
            error_code[0] = -2147024882;
            return -2147024882;
        }
    }
}

#endif