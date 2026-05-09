#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CScoreManager::ResetScore(CScoreManager *this)
{
  int v2; // eax
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CScoreManager::ResetScore", 0);
  v2 = *(uint32_t *)this;
  v4 = 0;
  *((uint32_t *)this + 10) = 0;
  (*(void (__thiscall **)(CScoreManager *))(v2 + 4))(this);
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
