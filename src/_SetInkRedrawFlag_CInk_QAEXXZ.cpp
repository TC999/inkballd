#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CInk::SetInkRedrawFlag(CInk *this)
{
  uint8_t v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CInk::SetInkRedrawFlag", 0);
  *((uint32_t *)this + 3) = 1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
