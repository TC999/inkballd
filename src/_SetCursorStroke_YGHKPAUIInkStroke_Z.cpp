#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void __stdcall SetCursorStroke(uint32_t a1, void* a2)
{
  uint8_t v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "SetCursorStroke", 0);
  v4 = 0;
  if ( g_pIStroke )
  {
    (*(void (__stdcall **)(void*, uint32_t, void*))(**((uint32_t **)g_pIStroke) + 8))(g_pIStroke, a1, a2);
  }
  v4 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
}
