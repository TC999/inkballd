#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void GetMovementRect_CMovingObject(CMovingObject* self, struct tagRECT *a2)
{
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  double v6; // st7
  bool v7; // c0
  bool v8; // c3
  double v9; // st7
  double v10; // st7
  uint8_t v11[8]; // [esp+8h] [ebp-Ch] BYREF
  int v12; // [esp+10h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock *>(v11), "CMovingObject::GetMovementRect", 0);
  v3 = *((uint32_t *)self + 6);
  if ( v3 <= *((uint32_t *)self + 28) )
    v3 = *((uint32_t *)self + 28);
  v4 = v3 + 2;
  v5 = *((uint32_t *)self + 7);
  if ( v5 <= *((uint32_t *)self + 29) )
    v5 = *((uint32_t *)self + 29);
  v6 = *((double *)self + 10);
  v7 = v6 < *((double *)self + 1);
  v8 = v6 == *((double *)self + 1);
  v12 = v5 + 2;
  if ( v7 || v8 )
  {
    a2->left = (int)*((double *)self + 10);
    v9 = *((double *)self + 1);
  }
  else
  {
    a2->left = (int)*((double *)self + 1);
    v9 = *((double *)self + 10);
  }
  a2->right = v4 + (int)v9;
  if ( *((double *)self + 11) <= *((double *)self + 2) )
  {
    a2->top = (int)*((double *)self + 11);
    v10 = *((double *)self + 2);
  }
  else
  {
    a2->top = (int)*((double *)self + 2);
    v10 = *((double *)self + 11);
  }
  a2->bottom = v12 + (int)v10;
  reinterpret_cast<Helpers::CLogBlock*>(v11)->~CLogBlock();
}
