#if 0
#include "global_types.h"
#include <cstdint>
#include <new>

extern "C" {
    CTimeManager* CTimeManager::CTimeManager(CTimeManager* this_ptr)
    {
      IDirectDrawSurface7* ddraw_surface; // eax
      IDirectDrawSurface7Vtbl* vtable; // edi
      IDirectDrawSurface7* game_surface; // eax
      char* bitmap_rect; // [esp-8h] [ebp-40h]
      uint8_t exception_object[12]; // [esp+10h] [ebp-28h] BYREF
      uint8_t log_buffer[8]; // [esp+1Ch] [ebp-1Ch] BYREF
      IDirectDrawSurface7* target_surface; // [esp+24h] [ebp-14h]
      int error_code[3]; // [esp+28h] [ebp-10h] BYREF
      int cleanup_flag; // [esp+34h] [ebp-4h]

      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CTimeManager::`vftable`);
      error_code[0] = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CTimeManager::CTimeManager", error_code);
      *reinterpret_cast<uint32_t*>(this_ptr + 1) = 486;
      *reinterpret_cast<uint32_t*>(this_ptr + 5) = 486;
      *reinterpret_cast<uint32_t*>(this_ptr + 2) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 3) = 58;
      *reinterpret_cast<uint32_t*>(this_ptr + 4) = 42;
      *reinterpret_cast<uint32_t*>(this_ptr + 6) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 7) = 544;
      *reinterpret_cast<uint32_t*>(this_ptr + 8) = 42;
      cleanup_flag = 0;
      dwTimeDigitWidth = 9;
      dwTopDrawLoc = 13;
      dwLeftDrawDif = 3;
      if (CTimeManager::InitSurface(this_ptr) < 0)
      {
        new (exception_object) std::bad_alloc();
        _CxxThrowException(exception_object, (_ThrowInfo*)&_TI2_AVbad_alloc_std__);
      }
      ddraw_surface = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
      vtable = ddraw_surface->lpVtbl;
      target_surface = ddraw_surface;
      bitmap_rect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 109);
      game_surface = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
      vtable->BltFast(target_surface, 0, 0, game_surface, reinterpret_cast<LPRECT>(bitmap_rect), 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 9) = -1;
      cleanup_flag = -1;
      *reinterpret_cast<uint32_t*>(this_ptr + 10) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 11) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 12) = 1;
      *reinterpret_cast<uint32_t*>(this_ptr + 14) = 0;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
      return this_ptr;
    }
}
  DDrawSurface = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v9 = DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 109);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast(v9, 0, 0, v4, (LPRECT)BitmapRect, 0);
  *((_DWORD *)this + 9) = -1;
  v11 = -1;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 1;
  *((_DWORD *)this + 14) = 0;
  reinterpret_cast<Helpers::CLogBlock*>(v8)->~CLogBlock();
  return this;
}

#endif
