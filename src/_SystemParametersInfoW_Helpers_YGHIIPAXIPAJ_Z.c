BOOL __stdcall Helpers::SystemParametersInfoW(
        UINT uiAction,
        UINT uiParam,
        PVOID pvParam,
        UINT fWinIni,
        _DWORD *a5,
        int *a6)
{
  BOOL v6; // esi
  signed int LastError; // eax
  const char *v9[2]; // [esp+4h] [ebp-Ch] BYREF
  char v10[4]; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)v10 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "Helpers::SystemParametersInfoW", (int *)v10);
  v6 = SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);
  if ( !v6 )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    *(_DWORD *)v10 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x4Eu, &stru_10036F8, v10[0]);
  }
  if ( a5 )
    *a5 = *(_DWORD *)v10;
  Helpers::CLogBlock::~CLogBlock(v9);
  return v6;
}
