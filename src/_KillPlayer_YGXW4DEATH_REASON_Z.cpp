void __stdcall KillPlayer(int a1)
{
  bool v1; // zf
  const unsigned __int8 *LastLoadedBoardData; // eax
  int *v3; // [esp+0h] [ebp-82Ch]
  _BYTE v4[8]; // [esp+10h] [ebp-81Ch] BYREF
  BOOL v5; // [esp+18h] [ebp-814h]
  WCHAR Caption[512]; // [esp+1Ch] [ebp-810h] BYREF
  WCHAR Text[518]; // [esp+41Ch] [ebp-410h] BYREF
  int v8; // [esp+828h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "KillPlayer", 0);
  v1 = *((_DWORD *)g_pCGameManager + 1) == 0;
  *((_DWORD *)g_pCGameManager + 1) = 0;
  *((_DWORD *)g_pCGameManager + 3) = 0;
  v8 = 0;
  *((_DWORD *)g_pCGameManager + 4) = 0;
  v5 = v1;
  if ( !a1 )
  {
    Helpers::LoadStringW(0, (HINSTANCE)0x3A9A, Text, (unsigned __int16 *)0x200, 0, v3);
LABEL_6:
    Helpers::LoadStringW(0, (HINSTANCE)0x3A99, Caption, (unsigned __int16 *)0x200, 0, v3);
    MessageBoxW(*((HWND *)g_pCGameBoard + 2480), Text, Caption, 0);
    goto LABEL_7;
  }
  if ( a1 == 1 )
    Helpers::LoadStringW(0, (HINSTANCE)0x3A9B, Text, (unsigned __int16 *)0x200, 0, v3);
  if ( a1 != 2 )
    goto LABEL_6;
LABEL_7:
  CScoreManager::ResetScore(*((CScoreManager **)g_pCGameBoard + 2477));
  CTileManager::ResetTileCount(*((CTileManager **)g_pCGameBoard + 2478));
  if ( a1 != 2 )
  {
    LastLoadedBoardData = CBoardManager::GetLastLoadedBoardData((CBoardManager *)&g_CBoardManager);
    CGameManager::LoadBoard(g_pCGameManager, LastLoadedBoardData, -1);
    CGameManager::UpdateTime(g_pCGameManager);
  }
  (*(void (__thiscall **)(_DWORD))(**((_DWORD **)g_pCGameBoard + 2479) + 4))(*((_DWORD *)g_pCGameBoard + 2479));
  if ( !v5 )
    *((_DWORD *)g_pCGameManager + 1) = 1;
  v8 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
