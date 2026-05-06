LSTATUS __stdcall Helpers::RegCreateKeyExW(
        HKEY hKey,
        const WCHAR *lpSubKey,
        DWORD Reserved,
        LPWSTR lpClass,
        DWORD dwOptions,
        REGSAM samDesired,
        LPSECURITY_ATTRIBUTES lpSecurityAttributes,
        PHKEY phkResult,
        LPDWORD lpdwDisposition,
        unsigned int *a10,
        int *a11)
{
  LSTATUS Key; // eax
  LSTATUS v12; // esi
  unsigned int v13; // ecx
  const char *v15[2]; // [esp+4h] [ebp-Ch] BYREF
  int v16; // [esp+Ch] [ebp-4h] BYREF

  v16 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "Helpers::RegCreateKeyExW", &v16);
  Key = RegCreateKeyExW(
          hKey,
          lpSubKey,
          Reserved,
          lpClass,
          dwOptions,
          samDesired,
          lpSecurityAttributes,
          phkResult,
          lpdwDisposition);
  v12 = Key;
  if ( !Key )
    goto LABEL_7;
  v13 = Key;
  if ( Key > 0 )
    v13 = (unsigned __int16)Key | 0x80070000;
  v16 = v13;
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x3Bu, &stru_10036F8, v13);
LABEL_7:
    v13 = v16;
  }
  if ( a10 )
    *a10 = v13;
  Helpers::CLogBlock::~CLogBlock(v15);
  return v12;
}
