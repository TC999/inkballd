#include "global_types.h"
#include <cstdint>
#include <windows.h>
uint32_t GetScore_CScoreManager(CScoreManager* self, void* self)
{
  int v2;
  uint8_t v4[8];

  Helpers::CLogBlock::CLogBlock(v4, "CScoreManager::GetScore", 0);
  v2 = *((uint32_t *)self + 10);
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}
