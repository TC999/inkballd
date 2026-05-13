#include "global_types.h"
#include <cstdint>

extern "C" void* CScoreManager_vftable;

CScoreManager::~CScoreManager()
{
  int current_score;
  uint8_t log_buffer[16];
  int cleanup_flag;

  *((uint32_t*)this + 0) = reinterpret_cast<uint32_t>(&CScoreManager_vftable);
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CScoreManager::~CScoreManager", 0);
  current_score = *((uint32_t*)this + 9);
  cleanup_flag = 0;
  CRegistryManager::WriteHiScore(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager), current_score);
  cleanup_flag = -1;
  reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
