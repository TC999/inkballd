BOOL __stdcall Helpers::UpdateWindow(HWND hWnd, HWND a2, int *a3)
{
  BOOL updated; // esi
  signed int LastError; // eax
  const char *v6[2]; // [esp+4h] [ebp-Ch] BYREF
  char v7[4]; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)v7 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "Helpers::UpdateWindow", (int *)v7);
  updated = UpdateWindow(hWnd);
  if ( !updated )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    *(_DWORD *)v7 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x5Au, &stru_10036F8, v7[0]);
  }
  if ( a2 )
    *(_DWORD *)a2 = *(_DWORD *)(HWND)v7;
  Helpers::CLogBlock::~CLogBlock(v6);
  return updated;
}
