#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CMovingObject::PrepareToMove(CMovingObject *this)
{
  int v2; // eax
  double v3; // st7
  int v4; // eax
  uint8_t v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CMovingObject::PrepareToMove", 0);
  v2 = *((uint32_t *)this + 6);
  *((double *)this + 10) = *((double *)this + 1);
  v3 = *((double *)this + 2);
  *((uint32_t *)this + 28) = v2;
  v4 = *((uint32_t *)this + 7);
  *((double *)this + 11) = v3;
  *((double *)this + 12) = *((double *)this + 1);
  *((uint32_t *)this + 29) = v4;
  *((double *)this + 13) = *((double *)this + 2);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
