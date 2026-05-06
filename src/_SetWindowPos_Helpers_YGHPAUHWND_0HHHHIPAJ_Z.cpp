BOOL __stdcall Helpers::SetWindowPos(
        HWND hWnd,
        HWND hWndInsertAfter,
        HWND X,
        int Y,
        int a5,
        int cy,
        UINT uFlags,
        _DWORD *a8,
        int *a9)
{
  BOOL v9; // esi
  signed int LastError; // eax
  const char *v12[2]; // [esp+4h] [ebp-Ch] BYREF
  char v13[4]; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "Helpers::SetWindowPos", (int *)v13);
  v9 = SetWindowPos(hWnd, hWndInsertAfter, (int)X, Y, a5, cy, uFlags);
  if ( !v9 )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    *(_DWORD *)v13 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x5Bu, &stru_10036F8, v13[0]);
  }
  if ( a8 )
    *a8 = *(_DWORD *)v13;
  Helpers::CLogBlock::~CLogBlock(v12);
  return v9;
}
