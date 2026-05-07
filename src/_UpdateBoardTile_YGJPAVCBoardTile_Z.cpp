#include <cstdint>
#include <windows.h>

extern "C" {
    int __stdcall UpdateBoardTile(RECT** tile_rect)
    {
      int blt_result; // eax
      IDirectDrawSurface7* board_buffer; // ebx
      int (__stdcall **blt_func)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t); // esi
      IDirectDrawSurface7* ddraw_surface; // eax
      int final_result; // esi
      RECT* source_rect; // [esp-Ch] [ebp-44h]
      RECT bounding_rect; // [esp+10h] [ebp-28h] BYREF
      uint8_t log_buffer[8]; // [esp+20h] [ebp-18h] BYREF
      int error_code[3]; // [esp+28h] [ebp-10h] BYREF
      int cleanup_flag; // [esp+34h] [ebp-4h]

      error_code[0] = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "UpdateBoardTile", error_code);
      cleanup_flag = 0;
      CBoardObject::GetBoundingRect(reinterpret_cast<CBoardObject*>(tile_rect), &bounding_rect);
      if (*reinterpret_cast<uint32_t*>(g_pCGameBoard + 2475) == 1)
      {
        blt_result = CDisplay::BltToBoard(
                      g_pDisplay,
                      *reinterpret_cast<uint64_t*>(reinterpret_cast<double*>(tile_rect) + 1),
                      *reinterpret_cast<uint64_t*>(reinterpret_cast<double*>(tile_rect) + 2),
                      g_pGamePiecesSurface,
                      tile_rect[8]);
      }
      else
      {
        board_buffer = CDisplay::GetBoardBuffer(g_pDisplay);
        source_rect = tile_rect[8];
        blt_func = reinterpret_cast<int (__stdcall **)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)>(&board_buffer->lpVtbl->Blt);
        ddraw_surface = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        blt_result = (*blt_func)(board_buffer, &bounding_rect, ddraw_surface, source_rect, 0, 0);
      }
      error_code[0] = blt_result;
      if (blt_result >= 0)
      {
        error_code[0] = BltBoardToInk(&bounding_rect);
        if (error_code[0] >= 0)
          error_code[0] = CDisplay::BltInk(g_pDisplay, &bounding_rect);
      }
      final_result = error_code[0];
      cleanup_flag = -1;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return final_result;
    }
}
