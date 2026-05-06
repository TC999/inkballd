int __stdcall SearchBoardList(unsigned __int16 *a1, unsigned __int8 *a2, int a3, struct BoardCollection *a4, int *a5)
{
  unsigned __int8 *v6; // eax
  int v7; // esi
  size_t v8; // esi
  int v9; // esi
  HWND MainWindowHwnd; // eax
  int *v12; // [esp+0h] [ebp-434h]
  _BYTE v13[8]; // [esp+10h] [ebp-424h] BYREF
  wchar_t *String1; // [esp+18h] [ebp-41Ch]
  void *Src; // [esp+1Ch] [ebp-418h]
  int v16; // [esp+20h] [ebp-414h]
  WCHAR String[518]; // [esp+24h] [ebp-410h] BYREF
  int v18; // [esp+430h] [ebp-4h]

  String1 = a1;
  Src = a2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "SearchBoardList", 0);
  v18 = 0;
  v16 = 0;
  if ( a3 <= 0 )
  {
LABEL_5:
    v9 = 0;
  }
  else
  {
    while ( 1 )
    {
      if ( !__wcsicmp(String1, (const wchar_t *)a4 + 2) )
      {
        v6 = (unsigned __int8 *)&g_BoardData + *(_DWORD *)a4;
        v7 = *v6++ << 8;
        v8 = *v6 + v7;
        memcpy(Src, v6 + 1, v8);
        if ( v8 <= 0x1000 )
          break;
      }
      ++v16;
      a4 = (struct BoardCollection *)((char *)a4 + 516);
      if ( v16 >= a3 )
        goto LABEL_5;
    }
    memcpy(&g_pLastLoadedLevel, Src, v8);
    *a5 = -1;
    memset(String, 0, 1024);
    Helpers::LoadStringW(0, (HINSTANCE)0x3A98, String, (unsigned __int16 *)0x200, 0, v12);
    MainWindowHwnd = GetMainWindowHwnd();
    SetWindowTextW(MainWindowHwnd, String);
    v9 = 1;
  }
  v18 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
  return v9;
}
