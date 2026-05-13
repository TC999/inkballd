#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CInk::SetInkRedrawFlag(void* self)
{
  uint8_t v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v2), "CInk::SetInkRedrawFlag", 0);
  *((uint32_t *)self + 3) = 1;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}
