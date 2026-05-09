#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall SetMenuChecks(HWND hWnd)
{
  HMENU Menu; // eax
  UINT v2; // esi
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "SetMenuChecks", 0);
  Menu = GetMenu(hWnd);
  switch ( dword_10D2F1C )
  {
    case 0:
      v2 = 40002;
LABEL_11:
      CheckMenuItem(Menu, v2, 8u);
      iLastChecked = v2;
      break;
    case 1:
      v2 = 40003;
      goto LABEL_11;
    case 2:
      v2 = 40004;
      goto LABEL_11;
    case 3:
      v2 = 40005;
      goto LABEL_11;
    case 4:
      v2 = 40006;
      goto LABEL_11;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
