#include "global_types.h"
#include <cstdint>
#include <new>
extern "C" void* CScoreManager_vftable;

extern "C" {
  void CScoreManager_CScoreManager(CScoreManager* self)
    {
      int hi_score; // eax
      uint8_t exception_object[12]; // [esp+10h] [ebp-20h] BYREF
      uint8_t log_buffer[16]; // [esp+1Ch] [ebp-14h] BYREF
      int cleanup_flag; // [esp+2Ch] [ebp-4h]

      *((uint32_t*)self + 0) = reinterpret_cast<uint32_t>(&CScoreManager_vftable);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CScoreManager::CScoreManager", 0);
      *((uint32_t*)self + 1) = 104;
      *((uint32_t*)self + 5) = 104;
      cleanup_flag = 0;
      *((uint32_t*)self + 2) = 0;
      *((uint32_t*)self + 3) = 341;
      *((uint32_t*)self + 4) = 42;
      *((uint32_t*)self + 6) = 0;
      *((uint32_t*)self + 7) = 445;
      *((uint32_t*)self + 8) = 42;
      if (CScoreManager::InitSurface(self) < 0)
      {
        new (exception_object) std::bad_alloc();
        // [TODO] CxxThrowException
      }
      CSurface::Clear(reinterpret_cast<CSurface*>(g_pScoreManagerSurface), 0);
      *((uint32_t*)self + 10) = 0;
      hi_score = CRegistryManager::ReadHiScore(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager));
      cleanup_flag = -1;
      *((uint32_t*)self + 9) = hi_score;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

CScoreManager::~CScoreManager()
{
    int current_score;
    uint8_t log_buffer[16];
    int cleanup_flag;

    *((uint32_t*)self + 0) = reinterpret_cast<uint32_t>(&CScoreManager_vftable);
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CScoreManager::~CScoreManager", 0);
    current_score = *((uint32_t*)self + 9);
    cleanup_flag = 0;
    CRegistryManager::WriteHiScore(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager), current_score);
    cleanup_flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}