#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall FreeCursorStroke()
{
  uint8_t v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "FreeCursorStroke", 0);
  v2 = 0;
  if ( g_pIStroke )
    (*(void (__stdcall **)(struct IInkStroke *))(*(uint32_t *)g_pIStroke + 8))(g_pIStroke);
  g_pIStroke = 0;
  v2 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
  return 0;
}
