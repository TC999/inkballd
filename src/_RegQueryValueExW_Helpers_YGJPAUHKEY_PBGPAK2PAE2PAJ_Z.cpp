LSTATUS __stdcall Helpers::RegQueryValueExW(
        HKEY hKey,
        const WCHAR *lpValueName,
        LPDWORD lpReserved,
        LPDWORD lpType,
        LPBYTE lpData,
        LPDWORD lpcbData,
        unsigned int *a7,
        int *a8)
{
  LSTATUS Value; // eax
  LSTATUS v9; // esi
  unsigned int v10; // ecx
  const char *v12[2]; // [esp+4h] [ebp-Ch] BYREF
  int v13; // [esp+Ch] [ebp-4h] BYREF

  v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "Helpers::RegQueryValueExW", &v13);
  Value = RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
  v9 = Value;
  if ( !Value )
    goto LABEL_7;
  v10 = Value;
  if ( Value > 0 )
    v10 = (unsigned __int16)Value | 0x80070000;
  v13 = v10;
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x3Cu, &stru_10036F8, v10);
LABEL_7:
    v10 = v13;
  }
  if ( a7 )
    *a7 = v10;
  Helpers::CLogBlock::~CLogBlock(v12);
  return v9;
}
