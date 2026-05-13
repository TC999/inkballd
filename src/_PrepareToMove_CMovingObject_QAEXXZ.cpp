#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void PrepareToMove_CMovingObject(CMovingObject *self)
{
  int v2; // eax
  double v3; // st7
  int v4; // eax
  uint8_t v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "CMovingObject::PrepareToMove", 0);
  v2 = *((uint32_t *)self + 6);
  *((double *)self + 10) = *((double *)self + 1);
  v3 = *((double *)self + 2);
  *((uint32_t *)self + 28) = v2;
  v4 = *((uint32_t *)self + 7);
  *((double *)self + 11) = v3;
  *((double *)self + 12) = *((double *)self + 1);
  *((uint32_t *)self + 29) = v4;
  *((double *)self + 13) = *((double *)self + 2);
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
}
