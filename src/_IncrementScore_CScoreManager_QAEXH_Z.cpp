#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CScoreManager::IncrementScore(CScoreManager *this, int a2)
{
  uint32_t v3; // eax
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CScoreManager::IncrementScore", 0);
  *((uint32_t *)this + 10) += a2;
  v3 = *((uint32_t *)this + 10);
  v5 = 0;
  if ( v3 >= *((uint32_t *)this + 9) )
    *((uint32_t *)this + 9) = v3;
  (*(void (__thiscall **)(CScoreManager *))(*(uint32_t *)this + 4))(this);
  v5 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}

#endif
