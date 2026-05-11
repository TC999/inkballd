#if 0
#include "global_types.h"
#include <cstdint>

extern "C" {
    CGameManager* CGameManager::CGameManager(CGameManager* this_ptr, HWND window_handle)
    {
      uint32_t* board_memory; // ecx
      CGameBoard* game_board; // eax
      uint8_t log_buffer[8]; // [esp+10h] [ebp-1Ch] BYREF
      void* board_ptr; // [esp+18h] [ebp-14h]
      int init_step; // [esp+28h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CGameManager::CGameManager", 0);
      init_step = 1;
      g_pCGameBoard = 0;
      board_memory = operator new(0x26C8u);
      board_ptr = board_memory;
      init_step = 2;
      if (board_memory)
        game_board = reinterpret_cast<CGameBoard*>(CGameBoard::CGameBoard(board_memory, window_handle, reinterpret_cast<void*>(1)));
      else
        game_board = 0;
      g_pCGameBoard = game_board;
      *reinterpret_cast<uint32_t*>(this_ptr + 4) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 1) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 2) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 3) = 0;
      CGameManager::UpdateTime(this_ptr);
      init_step = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
      return this_ptr;
    }
}

#endif
