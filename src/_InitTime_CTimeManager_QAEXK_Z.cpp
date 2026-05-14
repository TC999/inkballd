#include "global_types.h"
#include <cstdint>
#include <windows.h>
void InitTime_CTimeManager(CTimeManager* self, uint32_t a2)
{
  uint8_t v3[8];

  Helpers::CLogBlock::CLogBlock(v3, "CTimeManager::InitTime", 0);
  *((uint32_t *)self + 9) = a2;
  if ( a2 != -1 && a2 > 0xF3E58 )
    *((uint32_t *)self + 9) = 999000;
  *((uint32_t *)self + 13) = 0;
  *((uint32_t *)self + 10) = 0;
  *((uint32_t *)self + 14) = 0;
  *((uint32_t *)self + 12) = 1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
