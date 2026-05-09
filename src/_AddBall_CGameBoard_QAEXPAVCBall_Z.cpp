#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CGameBoard::AddBall(CGameBoard *this, CBall*a2)
{
  uint32_t *v3; // eax
  int v4; // edx
  uint8_t v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::AddBall", 0);
  v3 = (uint32_t *)(reinterpret_cast<char*>(this) + 2624);
  v4 = *((uint32_t *)this + 656);
  if ( v4 < 64 )
  {
    *((uint32_t *)a2 + 41) = v4;
    *((uint32_t *)this + (*v3)++ + 657) = a2;
    ++*((uint32_t *)this + 2473);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
