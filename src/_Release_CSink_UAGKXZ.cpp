#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
LONG __stdcall CSink::Release(volatile long*this)
{
  LONG v1; // edi
  uint8_t v3[8]; // [esp+8h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CSink::Release", 0);
  v1 = InterlockedDecrement(this + 1);
  if ( !v1 )
    operator delete((void*)this);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return v1;
}
