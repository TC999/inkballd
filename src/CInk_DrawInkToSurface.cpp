//----- (0100BA9A) --------------------------------------------------------
// DECOMPILE TODO: CInk_DrawInkToSurface - Complex IRenderInk vtable call
// Original code calls IRenderInk::DrawToSurface via vtable offset +16
// Requires correct IRenderInk interface definition

#include "global_types.h"
#include <cstdint>

void CInk_DrawInkToSurface(CInk *self, struct tagRECT *a2)
{
  uint8_t v5[8];
  int v7[3];

  v7[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v5), "CInk::DrawInkToSurface", v7);
  
  // DECOMPILE TODO: Call IRenderInk::DrawToSurface via vtable
  // Original: (*(int (__stdcall **)(IRenderInk*, HDC, void*, HWND*, uint32))(vtable + 16))
  (void)self;
  (void)a2;
  
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
}
