#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CUIBarObject::GetBoundingRect(CUIBarObject *this, struct tagRECT *a2)
{
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CUIBarObject::GetBoundingRect", 0);
  *a2 = *(struct tagRECT *)(reinterpret_cast<char*>(this) + 20);
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}

#endif
