#include <cstdint>
#include <new>

extern "C" {
    CScoreManager* CScoreManager::CScoreManager(CScoreManager* this_ptr)
    {
      int hi_score; // eax
      uint8_t exception_object[12]; // [esp+10h] [ebp-20h] BYREF
      uint8_t log_buffer[16]; // [esp+1Ch] [ebp-14h] BYREF
      int cleanup_flag; // [esp+2Ch] [ebp-4h]

      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CScoreManager::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CScoreManager::CScoreManager", 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 1) = 104;
      *reinterpret_cast<uint32_t*>(this_ptr + 5) = 104;
      cleanup_flag = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 2) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 3) = 341;
      *reinterpret_cast<uint32_t*>(this_ptr + 4) = 42;
      *reinterpret_cast<uint32_t*>(this_ptr + 6) = 0;
      *reinterpret_cast<uint32_t*>(this_ptr + 7) = 445;
      *reinterpret_cast<uint32_t*>(this_ptr + 8) = 42;
      if (CScoreManager::InitSurface(this_ptr) < 0)
      {
        new (exception_object) std::bad_alloc();
        _CxxThrowException(exception_object, (_ThrowInfo*)&_TI2_AVbad_alloc_std__);
      }
      CSurface::Clear(g_pScoreManagerSurface, 0);
      *reinterpret_cast<uint32_t*>(this_ptr + 10) = 0;
      hi_score = CRegistryManager::ReadHiScore(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager));
      cleanup_flag = -1;
      *reinterpret_cast<uint32_t*>(this_ptr + 9) = hi_score;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return this_ptr;
    }
}
  CSurface::Clear(g_pScoreManagerSurface, 0);
  *((_DWORD *)this + 10) = 0;
  HiScore = CRegistryManager::ReadHiScore((CRegistryManager *)&g_CRegistryManager);
  v6 = -1;
  *((_DWORD *)this + 9) = HiScore;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return this;
}
