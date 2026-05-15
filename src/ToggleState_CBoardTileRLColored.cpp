#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <new>
void ToggleState_CBoardTileRLColored(CBoardTileRLColored* self)
{
  uint8_t v2[8];

  new (v2) Helpers::CLogBlock(v2, "CBoardTileRLColored::ToggleState", 0);
  *((uint32_t *)self + 23) = *((uint32_t *)self + 23) == 0;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}
