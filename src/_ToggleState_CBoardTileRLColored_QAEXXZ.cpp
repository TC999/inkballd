#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CBoardTileRLColored::ToggleState(void* self)
{
  uint8_t v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v2), "CBoardTileRLColored::ToggleState", 0);
  *((uint32_t *)self + 23) = *((uint32_t *)self + 23) == 0;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}
