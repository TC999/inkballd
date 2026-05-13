#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CScoreManager::ResetScore(void* self)
{
  int v2; // eax
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CScoreManager::ResetScore", 0);
  v2 = *(uint32_t *)self;
  v4 = 0;
  *((uint32_t *)self + 10) = 0;
  (*(void (__thiscall **)(void*))(v2 + 4))(self);
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
