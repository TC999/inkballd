#include "global_types.h"
#include <cstdint>

extern "C" {
  void CSurface_CSurface(CSurface* self)
    {
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSurface::CSurface", 0);
      *((uint32_t*)self + 0) = 0;
      *((uint32_t*)self + 8) = 0;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
  CSurface::~CSurface()
  {
      int interface_ptr; // eax
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSurface::~CSurface", 0);
      interface_ptr = *((uint32_t*)self + 0);
      cleanup_flag = 0;
      if (interface_ptr)
      {
          (*(void(__stdcall**)(uint32_t))(*reinterpret_cast<uint32_t*>(interface_ptr) + 8))(interface_ptr);
          *((uint32_t*)self + 0) = 0;
      }
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
  }
}
