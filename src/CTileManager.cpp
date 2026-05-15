#include "global_types.h"
#include <cstdint>
#include <new>
extern "C" void* CTileManager_vftable;

extern "C" {
  void CTileManager_CTileManager(CTileManager* self)
    {
      uint8_t exception_object[12]; // [esp+10h] [ebp-20h] BYREF
      uint8_t log_buffer[16]; // [esp+1Ch] [ebp-14h] BYREF
      int cleanup_flag; // [esp+2Ch] [ebp-4h]

      *((uint32_t*)self + 0) = reinterpret_cast<uint32_t>(&CTileManager_vftable);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CTileManager::CTileManager", 0);
      *((uint32_t*)self + 1) = 445;
      *((uint32_t*)self + 5) = 445;
      cleanup_flag = 0;
      *((uint32_t*)self + 2) = 0;
      *((uint32_t*)self + 3) = 42;
      *((uint32_t*)self + 4) = 42;
      *((uint32_t*)self + 6) = 0;
      *((uint32_t*)self + 7) = 487;
      *((uint32_t*)self + 8) = 42;
      if (CTileManager::InitSurface(self) < 0)
      {
        new (exception_object) std::bad_alloc();
        // [TODO] CxxThrowException
      }
      cleanup_flag = -1;
      *((uint32_t*)self + 9) = 0;
      *((uint32_t*)self + 10) = 0;
      *((uint32_t*)self + 11) = 1600;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}
