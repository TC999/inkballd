#include "global_types.h"
#include <cstdint>
#include <new>

extern "C" {
    int __stdcall AddBallToBoard(int ball_type)
    {
      char* bitmap_rect; // eax
      CBall* ball; // esi
      uint8_t log_buffer[8]; // [esp+10h] [ebp-20h] BYREF
      void* ball_memory; // [esp+18h] [ebp-18h]
      int error_code[4]; // [esp+1Ch] [ebp-14h] BYREF
      int init_step; // [esp+2Ch] [ebp-4h]

      error_code[0] = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "AddBallToBoard", error_code);
      init_step = 1;
      ball_memory = operator new(0x1A8u);
      init_step = 2;
      if (ball_memory)
      {
        bitmap_rect = CGameBoard::GetBitmapRect(ball_type + 2);
        ball = reinterpret_cast<CBall*>(CBall::CBall(reinterpret_cast<int>(ball_memory), reinterpret_cast<int>(bitmap_rect), ball_type, 1, *reinterpret_cast<uint32_t*>(g_pCGameBoard + 2471)));
      }
      else
      {
        ball = 0;
      }
      init_step = 0;
      if (ball)
      {
        CBall::AddRef(ball);
        *reinterpret_cast<uint32_t*>(ball + 6) = *reinterpret_cast<uint32_t*>(g_pCGameBoard + 2471);
        *reinterpret_cast<uint32_t*>(ball + 7) = *reinterpret_cast<uint32_t*>(g_pCGameBoard + 2471);
        *reinterpret_cast<uint32_t*>(ball + 39) = 0;
        *reinterpret_cast<uint32_t*>(ball + 40) = 0;
        CGameBoard::AddBall(g_pCGameBoard, ball);
        init_step = -1;
        error_code[0] = 0;
        Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
        return 0;
      }
      else
      {
        init_step = -1;
        error_code[0] = -2147024882; // E_OUTOFMEMORY
        Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
        return -2147024882;
      }
    }
}
  else
  {
    v2 = 0;
  }
  v7 = 0;
  if ( v2 )
  {
    CBall::AddRef(v2);
    *((_DWORD *)v2 + 6) = *((_DWORD *)g_pCGameBoard + 2471);
    *((_DWORD *)v2 + 7) = *((_DWORD *)g_pCGameBoard + 2471);
    *((_DWORD *)v2 + 39) = 0;
    *((_DWORD *)v2 + 40) = 0;
    CGameBoard::AddBall(g_pCGameBoard, v2);
    v7 = -1;
    v6[0] = 0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
    return 0;
  }
  else
  {
    v7 = -1;
    v6[0] = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
    return -2147024882;
  }
}
