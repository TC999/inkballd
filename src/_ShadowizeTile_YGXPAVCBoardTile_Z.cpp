#include "global_types.h"
#include <cstdint>
#include <new>

extern "C" {
    void ShadowizeTile(CBoardTile* tile)
    {
      uint8_t log_buffer[16];
      int cleanup_flag;

      new (log_buffer) Helpers::CLogBlock(log_buffer, "ShadowizeTile", 0);
      cleanup_flag = 0;
      CGameBoard::ShadowizeTile(g_pCGameBoard, tile, 0);
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}
