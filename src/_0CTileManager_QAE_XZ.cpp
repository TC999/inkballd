#include "global_types.h"
#include <cstdint>
#include <new>

extern "C" {
    CTileManager* CTileManager::CTileManager(CTileManager* this_ptr)
    {
      uint8_t exception_object[12]; // [esp+10h] [ebp-20h] BYREF
      uint8_t log_buffer[16]; // [esp+1Ch] [ebp-14h] BYREF
      int cleanup_flag; // [esp+2Ch] [ebp-4h]

      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CTileManager::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CTileManager::CTileManager", 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 1) = 445;
      *reinterpret_cast<uint32_t*>(this_ptr + 5) = 445;
      cleanup_flag = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 2) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 3) = 42;
      *reinterpret_cast<uint32_t*>(this_ptr + 4) = 42;
      *reinterpret_cast<uint32_t*>(this_ptr + 6) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 7) = 487;
      *reinterpret_cast<uint32_t*>(this_ptr + 8) = 42;
      if (CTileManager::InitSurface(this_ptr) < 0)
      {
        new (exception_object) std::bad_alloc();
        _CxxThrowException(exception_object, (_ThrowInfo*)&_TI2_AVbad_alloc_std__);
      }
      cleanup_flag = -1;
      *reinterpret_cast<uint32_t*>(this_ptr + 9) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 10) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 11) = 1600;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
  v5 = -1;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 1600;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return this;
}
