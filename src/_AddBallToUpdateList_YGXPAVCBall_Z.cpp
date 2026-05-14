#include "global_types.h"
#include <cstdint>

extern "C" {
    void __stdcall AddBallToUpdateList(void* ball)
    {
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "AddBallToUpdateList", 0);
      cleanup_flag = 0;
      CGameBoard::AddBallToUpdateList(g_pCGameBoard, (CBall*)ball);
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

