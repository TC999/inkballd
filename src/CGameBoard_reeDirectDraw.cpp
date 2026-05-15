#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void CGameBoard::FreeDirectDraw(CGameBoard* self)
{
  uint8_t v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v1), "CGameBoard::FreeDirectDraw", 0);
  v2 = 0;
  if ( g_pTimeManagerSurface )
  {
    CSurface::scalar_deleting_destructor((CSurface*)g_pTimeManagerSurface, 1);
    g_pTimeManagerSurface = 0;
  }
  if ( g_pBallManagerSurface )
  {
    CSurface::scalar_deleting_destructor((CSurface*)g_pBallManagerSurface, 1);
    g_pBallManagerSurface = 0;
  }
  if ( g_pTileManagerSurface )
  {
    CSurface::scalar_deleting_destructor((CSurface*)g_pTileManagerSurface, 1);
    g_pTileManagerSurface = 0;
  }
  if ( g_pScoreManagerSurface )
  {
    CSurface::scalar_deleting_destructor((CSurface*)g_pScoreManagerSurface, 1);
    g_pScoreManagerSurface = 0;
  }
  if ( g_pDisplay )
  {
    CDisplay::scalar_deleting_destructor((CDisplay*)g_pDisplay, 1);
    g_pDisplay = 0;
  }
  v2 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}
