//----- (01005B15) --------------------------------------------------------
void __thiscall CBoardManager::LoadRandomBoardFromResources(unsigned __int8 *Src, int *a3)
{
  int RandomNumber; // esi
  unsigned __int8 *v4; // eax
  int v5; // esi
  size_t v6; // esi
  HWND MainWindowHwnd; // eax
  int *v8; // [esp+0h] [ebp-428h]
  _BYTE v9[8]; // [esp+10h] [ebp-418h] BYREF
  WCHAR String[518]; // [esp+18h] [ebp-410h] BYREF
  int v11; // [esp+424h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CBoardManager::LoadRandomBoardFromResources", 0);
  v11 = 0;
  do
    RandomNumber = GetRandomNumber(iBoardListCount);
  while ( fPrevSeen(RandomNumber, (struct BOARDHIST *)&g_bhPrevBoards, iBoardListCount) );
  v4 = (unsigned __int8 *)&g_BoardData + *((_DWORD *)paBoardList + 129 * RandomNumber);
  v5 = *v4++ << 8;
  v6 = *v4 + v5;
  memcpy(Src, v4 + 1, v6);
  if ( v6 <= 0x1000 )
    memcpy(&g_pLastLoadedLevel, Src, v6);
  *a3 = -1;
  Helpers::LoadStringW(0, (HINSTANCE)0x3A98, String, (unsigned __int16 *)0x200, 0, v8);
  MainWindowHwnd = GetMainWindowHwnd();
  SetWindowTextW(MainWindowHwnd, String);
  v11 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v9)->~CLogBlock();
}
