#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall ConvertInkRectToDisplayRect(struct tagRECT *a1, struct tagXFORM *a2)
{
  double right; // st7
  LONG v3; // eax
  double top; // st7
  LONG v5; // eax
  double bottom; // st7
  uint8_t v7[8]; // [esp+8h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "ConvertInkRectToDisplayRect", 0);
  right = (double)a1->right;
  a1->left = (int)((double)a1->left * a2->eM11);
  v3 = (int)(right * a2->eM11);
  top = (double)a1->top;
  a1->right = v3;
  v5 = (int)(top * a2->eM22);
  bottom = (double)a1->bottom;
  a1->top = v5;
  a1->bottom = (int)(bottom * a2->eM22);
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
}
