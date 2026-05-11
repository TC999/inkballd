#if 0
#include "global_types.h"
#include <cstdint>

extern "C" {
    void CScoreManager::~CScoreManager(CScoreManager* this_ptr)
    {
      int current_score; // [esp-4h] [ebp-28h]
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CScoreManager::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CScoreManager::~CScoreManager", 0);
      current_score = *reinterpret_cast<uint32_t*>(this_ptr + 9);
      cleanup_flag = 0;
      CRegistryManager::WriteHiScore(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager), current_score);
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

#endif
