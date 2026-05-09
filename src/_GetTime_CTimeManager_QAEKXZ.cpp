#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
uint32_t __thiscall CTimeManager::GetTime(CTimeManager *this)
{
  int v2; // esi
  uint8_t v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CTimeManager::GetTime", 0);
  v2 = *((uint32_t *)this + 9);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
