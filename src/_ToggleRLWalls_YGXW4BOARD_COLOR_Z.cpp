#if 0
#include "global_types.h"
#include <cstdint>

extern "C" {
    void __stdcall ToggleRLWalls(uint32_t color)
    {
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "ToggleRLWalls", 0);
      cleanup_flag = 0;
      CGameBoard::ToggleRLWalls(reinterpret_cast<CBoardTileRLColored**>(g_pCGameBoard), color);
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

#endif
