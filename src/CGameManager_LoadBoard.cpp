//----- (0100AECB) --------------------------------------------------------
void __thiscall CGameManager::LoadBoard(CGameManager *this, const unsigned __int8 *a2, int a3)
{
  int v4; // eax
  const unsigned __int8 *v5; // esi
  int v6; // eax
  unsigned __int8 *v7; // esi
  unsigned int v8; // eax
  unsigned int v9; // edx
  unsigned __int8 *v10; // esi
  int v11; // ecx
  unsigned __int8 *v12; // esi
  int v13; // ecx
  unsigned __int8 *v14; // esi
  int v15; // eax
  unsigned __int8 *v16; // esi
  int v17; // eax
  unsigned __int8 *v18; // esi
  struct CBoardTile *v19; // edi
  unsigned __int8 *v20; // esi
  int v21; // edi
  _BYTE *v22; // esi
  int v23; // ebx
  int v24; // eax
  const unsigned __int8 *v25; // ecx
  const unsigned __int8 *v26; // ebx
  unsigned __int8 v27; // al
  unsigned __int8 *v28; // esi
  int v29; // eax
  struct CBoardTile *v30; // eax
  unsigned __int8 *v31; // esi
  int v32; // eax
  int v33; // edi
  int v34; // edi
  struct CBoardTile *v35; // eax
  struct CBoardTile *v36; // ecx
  _BYTE v37[8]; // [esp+10h] [ebp-28h] BYREF
  struct CBoardTile *v38; // [esp+18h] [ebp-20h]
  const unsigned __int8 *v39; // [esp+1Ch] [ebp-1Ch]
  const unsigned __int8 *v40; // [esp+20h] [ebp-18h]
  int v41; // [esp+24h] [ebp-14h]
  int v42; // [esp+28h] [ebp-10h]
  int v43; // [esp+34h] [ebp-4h]
  int v44; // [esp+40h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CGameManager::LoadBoard", 0);
  v43 = 0;
  v44 = 0;
  v40 = &a2[a3];
  CGameBoard::ResetBoard(g_pCGameBoard);
  if ( a3 > 0 && (int)(a2 + 9) > (int)&a2[a3] )
    goto LABEL_8;
  v4 = *a2 << 8;
  v5 = a2 + 1;
  v6 = *v5 + v4;
  v7 = (unsigned __int8 *)(v5 + 1);
  if ( v6 )
  {
    if ( (unsigned int)(v6 - 1) > 0x3E6 )
      goto LABEL_8;
    v8 = 1000 * v6;
  }
  else
  {
    v8 = -1;
  }
  CTimeManager::InitTime(*((CTimeManager **)g_pCGameBoard + 2479), v8);
  CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, *((struct CGameObject **)g_pCGameBoard + 2479));
  v9 = 1000 * *v7;
  v10 = v7 + 1;
  if ( v9 > 0xEA60 )
    goto LABEL_8;
  v11 = *v10 << 8;
  v12 = v10 + 1;
  v13 = *v12 + v11;
  v14 = v12 + 1;
  if ( (unsigned int)(v13 - 50) > 0xFA )
    goto LABEL_8;
  v15 = *v14 << 8;
  v16 = v14 + 1;
  v17 = *v16 + v15;
  v18 = v16 + 1;
  if ( (unsigned int)(v17 - 50) > 0xFA )
    goto LABEL_8;
  if ( v13 > v17 )
    goto LABEL_8;
  v19 = (struct CBoardTile *)*v18;
  v20 = v18 + 1;
  v38 = v19;
  v21 = *v20;
  v22 = v20 + 1;
  if ( v21 > 64 )
    goto LABEL_8;
  v23 = 0;
  CBallManager::Init(*((CBallManager **)g_pCGameBoard + 2476), 0, v21, v9, v13, v17);
  CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, *((struct CGameObject **)g_pCGameBoard + 2476));
  if ( a3 <= 0 || (int)&v22[v21] <= (int)v40 )
  {
    if ( v21 > 0 )
    {
      do
      {
        v24 = AddBallToBoard((unsigned __int8)*v22++);
        v44 = v24;
        if ( v24 < 0 )
          break;
        ++v23;
      }
      while ( v23 < v21 );
    }
    if ( v38 )
      CGameBoard::RandomizeBallOrder(g_pCGameBoard);
  }
  else
  {
    v44 = -2147418113;
  }
  v42 = 0;
  if ( v44 < 0 )
    goto LABEL_8;
  do
  {
    if ( v42 >= *((_DWORD *)g_pCGameBoard + 2470) )
      break;
    v41 = 0;
    v25 = v22 + 4;
    v26 = v22 + 2;
    while ( v41 < *((_DWORD *)g_pCGameBoard + 2469) )
    {
      v27 = *v22;
      v44 = -2147024882;
      if ( (*v22 & 0xF0) == 0x40 )
      {
        if ( a3 > 0 && (int)v25 > (int)v40 )
        {
LABEL_40:
          v44 = -2147418113;
          break;
        }
        v31 = v22 + 1;
        v32 = *v31++ + (v27 << 8);
        v33 = *v31++ << 8;
        v34 = *v31 + v33;
        v22 = v31 + 1;
        v26 += 4;
        v39 = v25 + 4;
        v38 = BuildTileObject(v32, v41, v42);
        if ( v38 )
        {
          v35 = BuildTileObject(v34, v41, v42);
          if ( v35 )
          {
            v36 = v38;
            *((_DWORD *)v38 + 22) = v35;
            CGameBoard::SetTile(g_pCGameBoard, v36);
            goto LABEL_36;
          }
          operator delete(v38);
        }
      }
      else
      {
        if ( a3 > 0 && (int)v26 > (int)v40 )
          goto LABEL_40;
        v28 = v22 + 1;
        v29 = *v28 + (v27 << 8);
        v22 = v28 + 1;
        v26 += 2;
        v39 = v25 + 2;
        v30 = BuildTileObject(v29, v41, v42);
        if ( v30 )
        {
          CGameBoard::SetTile(g_pCGameBoard, v30);
LABEL_36:
          v44 = 0;
        }
      }
      ++v41;
      if ( v44 < 0 )
        break;
      v25 = v39;
    }
    ++v42;
  }
  while ( v44 >= 0 );
  if ( v44 < 0 )
LABEL_8:
    DisplayBoardLoadMsg();
  if ( CGameBoard::BltBoardToInk(g_pCGameBoard, 0, 0) == -2005532222 )
    CGameBoard::RestoreSurfaces((CScoreManager **)g_pCGameBoard);
  if ( CDisplay::BltInk(g_pDisplay, 0) == -2005532222 )
    CGameBoard::RestoreSurfaces((CScoreManager **)g_pCGameBoard);
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)g_pCGameBoard + 2479) + 4))(*((_DWORD *)g_pCGameBoard + 2479));
  CGameBoard::PerformUpdate(g_pCGameBoard, 0, 1);
  v43 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
}
