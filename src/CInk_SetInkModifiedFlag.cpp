//----- (0100B88A) --------------------------------------------------------
#include "global_types.h"
#include <cstdint>

void CInk_SetInkModifiedFlag(CInk *self)
{
  uint8_t v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v2), "CInk::SetInkModifiedFlag", 0);
  *((uint32_t*)self + 2) = 1;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}
