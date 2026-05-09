#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CBallManager::Init(CBallManager *this, int a2, int a3, uint32_t a4, int a5, int a6)
{
  uint8_t v7[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBallManager::Init", 0);
  *((uint32_t *)this + 20) = 0;
  *((uint32_t *)this + 9) = a2;
  *((uint32_t *)this + 10) = a3;
  *((uint32_t *)this + 11) = a4;
  *((uint32_t *)this + 324) = a5;
  *((uint32_t *)this + 325) = a6;
  memset(reinterpret_cast<char*>(this) + 84, 0, 0x4B0u);
  *((uint32_t *)this + 323) = 0;
  *((uint32_t *)this + 321) = 1;
  *((uint32_t *)this + 322) = 4000;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
