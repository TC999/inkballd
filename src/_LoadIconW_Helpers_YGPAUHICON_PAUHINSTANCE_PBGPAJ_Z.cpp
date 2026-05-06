HICON __stdcall Helpers::LoadIconW(HINSTANCE hInstance, const WCHAR *lpIconName, unsigned __int16 *a3, int *a4)
{
  HICON IconW; // esi
  signed int LastError; // eax
  const char *v7[2]; // [esp+4h] [ebp-Ch] BYREF
  char v8[4]; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)v8 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "Helpers::LoadIconW", (int *)v8);
  IconW = LoadIconW(hInstance, lpIconName);
  if ( !IconW )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    *(_DWORD *)v8 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Cu, &stru_10036F8, v8[0]);
  }
  if ( a3 )
    *(_DWORD *)a3 = *(_DWORD *)v8;
  Helpers::CLogBlock::~CLogBlock(v7);
  return IconW;
}
