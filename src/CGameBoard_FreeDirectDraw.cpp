//----- (01009749) --------------------------------------------------------
void CGameBoard::FreeDirectDraw(CGameBoard *self)
{
  _BYTE v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "CGameBoard::FreeDirectDraw", 0);
  v2 = 0;
  if ( g_pTimeManagerSurface )
  {
    delete g_pTimeManagerSurface;
    g_pTimeManagerSurface = 0;
  }
  if ( g_pBallManagerSurface )
  {
    delete g_pBallManagerSurface;
    g_pBallManagerSurface = 0;
  }
  if ( g_pTileManagerSurface )
  {
    delete g_pTileManagerSurface;
    g_pTileManagerSurface = 0;
  }
  if ( g_pScoreManagerSurface )
  {
    delete g_pScoreManagerSurface;
    g_pScoreManagerSurface = 0;
  }
  if ( g_pDisplay )
  {
    delete g_pDisplay;
    g_pDisplay = 0;
  }
  v2 = -1;
  ((Helpers::CLogBlock *)v1)->~CLogBlock();
}
