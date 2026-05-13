#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void GetInkBufferHDC(HDC *a1)
{
  uint8_t v2[8]; // [esp+10h] [ebp-18h] BYREF
  int v3[3]; // [esp+18h] [ebp-10h] BYREF
  int v4; // [esp+24h] [ebp-4h]

  v3[0] = -2147467259;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "GetInkBufferHDC", v3);
  *a1 = 0;
  v4 = 0;
  InkBuffer = CDisplay::GetInkBuffer(g_pDisplay);
  if ( InkBuffer )
    v3[0] = InkBuffer->lpVtbl->GetDC(InkBuffer, a1);
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
}
