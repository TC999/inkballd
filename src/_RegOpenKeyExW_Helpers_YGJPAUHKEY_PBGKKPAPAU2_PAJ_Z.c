LSTATUS __stdcall Helpers::RegOpenKeyExW(
        HKEY hKey,
        const WCHAR *lpSubKey,
        DWORD ulOptions,
        REGSAM samDesired,
        PHKEY phkResult,
        HKEY *a6,
        int *a7)
{
  LSTATUS v7; // eax
  LSTATUS v8; // esi
  HKEY v9; // ecx
  const char *v11[2]; // [esp+4h] [ebp-Ch] BYREF
  int v12; // [esp+Ch] [ebp-4h] BYREF

  v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "Helpers::RegOpenKeyExW", &v12);
  v7 = RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult);
  v8 = v7;
  if ( !v7 )
    goto LABEL_7;
  v9 = (HKEY)v7;
  if ( v7 > 0 )
    v9 = (HKEY)((unsigned __int16)v7 | 0x80070000);
  v12 = (int)v9;
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x39u, &stru_10036F8, (char)v9);
LABEL_7:
    v9 = (HKEY)v12;
  }
  if ( a6 )
    *a6 = v9;
  Helpers::CLogBlock::~CLogBlock(v11);
  return v8;
}
