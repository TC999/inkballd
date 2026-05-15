#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CGameBoard::QueryNewPallete(CGameBoard *self)
{
    IDirectDrawPalette* palette;
    IDirectDrawSurface7* FrontBuffer;
    uint32_t v2;
  uint8_t v3[8];
  IDirectDrawPalette* palette_array[3];
  int v5;

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)v3, "CGameBoard::QueryNewPallete", 0);
  v5 = 0;
  palette_array[0] = 0;
  FrontBuffer = (IDirectDrawSurface7*)CDisplay::GetFrontBuffer(g_pDisplay);
  FrontBuffer->lpVtbl->GetPalette(FrontBuffer, palette_array);
  v2 = (uint32_t)CDisplay::GetFrontBuffer(g_pDisplay);
  ((IDirectDrawSurface7*)v2)->lpVtbl->SetPalette((IDirectDrawSurface7*)v2, palette_array[0]);
  if ( palette_array[0] )
  {
    (*(void (__stdcall **)(IDirectDrawPalette*))(*(uint32_t *)palette_array[0] + 8))(palette_array[0]);
    palette_array[0] = 0;
  }
  v5 = -1;
  ((Helpers::CLogBlock*)v3)->~CLogBlock();
}
