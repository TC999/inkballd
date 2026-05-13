#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
LONG __stdcall Release_CSink(volatile long *self)
{
  LONG v1; // edi
  uint8_t v3[8]; // [esp+8h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CSink::Release", 0);
  v1 = InterlockedDecrement(self + 1);
  if ( !v1 )
    operator delete((void*)self);
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
  return v1;
}
