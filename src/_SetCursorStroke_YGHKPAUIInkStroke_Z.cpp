#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall SetCursorStroke(uint32_t a1, struct IInkStroke *a2)
{
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "SetCursorStroke", 0);
  v4 = 0;
  if ( g_pIStroke )
    (*(void (__stdcall **)(struct IInkStroke *))(*(uint32_t *)g_pIStroke + 8))(g_pIStroke);
  v4 = -1;
  g_pIStroke = a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return 0;
}
