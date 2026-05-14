#include "global_types.h"
#include <cstdint>
#include <new>

extern "C" {
    void ToggleRLWalls(uint32_t color)
    {
      uint8_t log_buffer[16];
      int cleanup_flag;

      new (log_buffer) Helpers::CLogBlock(log_buffer, "ToggleRLWalls", 0);
      cleanup_flag = 0;
      CGameBoard::ToggleRLWalls(g_pCGameBoard, static_cast<int>(color));
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

