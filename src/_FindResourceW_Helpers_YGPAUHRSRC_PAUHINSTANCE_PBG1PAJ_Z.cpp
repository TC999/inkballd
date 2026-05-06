HRSRC __stdcall Helpers::FindResourceW(
        HMODULE hModule,
        const WCHAR *lpName,
        LPCWSTR lpType,
        unsigned __int16 *a4,
        int *a5)
{
  HRSRC ResourceW; // esi
  signed int LastError; // eax
  const char *v8[2]; // [esp+4h] [ebp-Ch] BYREF
  char v9[4]; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "Helpers::FindResourceW", (int *)v9);
  ResourceW = FindResourceW(hModule, lpName, lpType);
  if ( !ResourceW )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    *(_DWORD *)v9 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x67u, &stru_10036F8, v9[0]);
  }
  if ( a4 )
    *(_DWORD *)a4 = *(_DWORD *)v9;
  Helpers::CLogBlock::~CLogBlock(v8);
  return ResourceW;
}
