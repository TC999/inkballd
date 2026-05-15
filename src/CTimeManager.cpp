#include "global_types.h"
#include <cstdint>
#include <new>
extern "C" void* CTimeManager_vftable;
extern uint32_t dwTimeDigitWidth;
extern uint32_t dwTopDrawLoc;
extern uint32_t dwLeftDrawDif;

extern "C" void* CTimeManager_vftable;

CTimeManager::CTimeManager()
{
  char* bitmap_rect;
  uint8_t log_buffer[8];
  int error_code;
  int cleanup_flag;

  *((uint32_t*)self + 0) = reinterpret_cast<uint32_t>(&CTimeManager_vftable);
  error_code = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CTimeManager::CTimeManager", error_code);
  *((uint32_t*)self + 1) = 486;
  *((uint32_t*)self + 5) = 486;
  *((uint32_t*)self + 2) = 0;
  *((uint32_t*)self + 3) = 58;
  *((uint32_t*)self + 4) = 42;
  *((uint32_t*)self + 6) = 0;
  *((uint32_t*)self + 7) = 544;
  *((uint32_t*)self + 8) = 42;
  cleanup_flag = 0;
  dwTimeDigitWidth = 9;
  dwTopDrawLoc = 13;
  dwLeftDrawDif = 3;
  if (CTimeManager::InitSurface(self) < 0)
  {
    // [TODO] exception handling
  }
  CSurface::GetDDrawSurface(reinterpret_cast<CSurface*>(g_pTimeManagerSurface));
  bitmap_rect = CBitmapRects::GetBitmapRect(reinterpret_cast<CBitmapRects*>(g_CBitmapRects), 109);
  CSurface::GetDDrawSurface(reinterpret_cast<CSurface*>(g_pGamePiecesSurface));
  *((uint32_t*)self + 9) = (uint32_t)-1;
  cleanup_flag = -1;
  *((uint32_t*)self + 10) = 0;
  *((uint32_t*)self + 11) = 0;
  *((uint32_t*)self + 12) = 1;
  *((uint32_t*)self + 14) = 0;
  reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
