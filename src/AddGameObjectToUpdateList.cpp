#include "global_types.h"
#include <cstdint>

extern "C" {
    void __stdcall AddGameObjectToUpdateList(void* game_object)
    {
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "AddGameObjectToUpdateList", 0);
      cleanup_flag = 0;
      CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, (CGameObject*)game_object);
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

