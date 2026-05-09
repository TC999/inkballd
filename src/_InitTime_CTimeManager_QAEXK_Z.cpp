#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CTimeManager::InitTime(CTimeManager *this, uint32_t a2)
{
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTimeManager::InitTime", 0);
  *((uint32_t *)this + 9) = a2;
  if ( a2 != -1 && a2 > 0xF3E58 )
    *((uint32_t *)this + 9) = 999000;
  *((uint32_t *)this + 13) = 0;
  *((uint32_t *)this + 10) = 0;
  *((uint32_t *)this + 14) = 0;
  *((uint32_t *)this + 12) = 1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
