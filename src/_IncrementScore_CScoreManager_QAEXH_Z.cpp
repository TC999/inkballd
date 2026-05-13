#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void IncrementScore_CScoreManager(CScoreManager* self, void* self, uint32_t a2)
{
  uint32_t v3; // eax
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CScoreManager::IncrementScore", 0);
  *((uint32_t *)self + 10) += a2;
  v3 = *((uint32_t *)self + 10);
  v5 = 0;
  if ( v3 >= *((uint32_t *)self + 9) )
    *((uint32_t *)self + 9) = v3;
  (*(void (__thiscall **)(void*))(*(uint32_t *)self + 4))(self);
  v5 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
