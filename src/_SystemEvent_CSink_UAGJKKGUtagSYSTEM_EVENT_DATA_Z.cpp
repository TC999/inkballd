#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    int __stdcall CSink::SystemEvent(CSink* this_ptr, uint32_t tablet_id, uint32_t context_id, int event_type, struct tagSYSTEM_EVENT_DATA event_data)
    {
      CTabletContextInfo* tablet_context; // eax
      RECT* playing_area_rect; // eax
      uint8_t log_buffer[8]; // [esp+4h] [ebp-Ch] BYREF
      int result_code; // [esp+Ch] [ebp-4h] BYREF

      result_code = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSink::SystemEvent", &result_code);
      if (static_cast<uint16_t>(event_type) == 21 && g_tcid == tablet_id && g_cid == context_id)
      {
        tablet_context = GetTabletContextInfo(g_tcid);
        if (tablet_context)
        {
          (*(void(__stdcall **)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))(**reinterpret_cast<uint32_t**>(tablet_context) + 36))(
            *reinterpret_cast<uint32_t*>(tablet_context),
            g_tcid,
            g_cid,
            0,
            0,
            0);
        }
        if ((*(int(__stdcall **)(IInkObject*, int*))(*reinterpret_cast<uint32_t*>(g_pIInkObject) + 16))(g_pIInkObject, &event_type) >= 0
          && event_type)
        {
          (*(void(__stdcall **)(IInkObject*, int, int))(*reinterpret_cast<uint32_t*>(g_pIInkObject) + 68))(g_pIInkObject, event_type - 1, 1);
          BltBoardToInk(0);
          CInk::SetInkRedrawFlag(*reinterpret_cast<CInk**>(g_pCGameBoard + 2481));
          playing_area_rect = CGameBoard::GetPlayingAreaRect(g_pCGameBoard);
          AddDisplayUpdateRect(playing_area_rect);
        }
      }
      result_code = 0;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return 0;
    }
}
