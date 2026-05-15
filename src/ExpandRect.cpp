#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall ExpandRect(struct tagRECT *a1, int a2)
{
  uint8_t v2[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "ExpandRect", 0);
  a1->top -= a2;
  a1->bottom += a2;
  a1->left -= a2;
  a1->right += a2;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}
