#include "global_types.h"
#include <cstdint>
#include <new>

extern "C" {
    int __stdcall AddBallToBoard(int ball_type)
    {
      char* bitmap_rect;
      CBall* ball;
      uint8_t log_buffer[8];
      void* ball_memory;
      int error_code;
      int init_step;

      error_code = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "AddBallToBoard", error_code);
      init_step = 1;
      ball_memory = operator new(0x1A8u);
      init_step = 2;
      if (ball_memory)
      {
        bitmap_rect = CGameBoard::GetBitmapRect(g_pCGameBoard, ball_type + 2);
        ball = reinterpret_cast<CBall*>(CBall_func((int)ball_memory, (int)bitmap_rect, ball_type, 1, *((uint32_t *)g_pCGameBoard + 2471)));
      }
      else
      {
        ball = 0;
      }
      init_step = 0;
      if (ball)
      {
        CBall::AddRef(ball);
        *((uint32_t *)ball + 6) = *((uint32_t *)g_pCGameBoard + 2471);
        *((uint32_t *)ball + 7) = *((uint32_t *)g_pCGameBoard + 2471);
        *((uint32_t *)ball + 39) = 0;
        *((uint32_t *)ball + 40) = 0;
        CGameBoard::AddBall(g_pCGameBoard, ball);
        init_step = -1;
        error_code = 0;
        reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
        return 0;
      }
      else
      {
        init_step = -1;
        error_code = -2147024882;
        reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
        return -2147024882;
      }
    }
}
