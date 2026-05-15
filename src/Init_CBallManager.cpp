#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void Init_CBallManager(CBallManager* self, int a2, int a3, uint32_t a4, int a5, int a6)
{
  uint8_t v7[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock *>(v7), "CBallManager::Init", 0);
  *((uint32_t *)self + 20) = 0;
  *((uint32_t *)self + 9) = a2;
  *((uint32_t *)self + 10) = a3;
  *((uint32_t *)self + 11) = a4;
  *((uint32_t *)self + 324) = a5;
  *((uint32_t *)self + 325) = a6;
  memset(reinterpret_cast<char*>(self) + 84, 0, 0x4B0u);
  *((uint32_t *)self + 323) = 0;
  *((uint32_t *)self + 321) = 1;
  *((uint32_t *)self + 322) = 4000;
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
}
