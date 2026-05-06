HICON __stdcall Helpers::LoadCursorW(HINSTANCE hInstance, const WCHAR *lpCursorName, unsigned __int16 *a3, int *a4)
{
  HCURSOR CursorW; // esi
  signed int LastError; // eax
  const char *v7[2]; // [esp+4h] [ebp-Ch] BYREF
  char v8[4]; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)v8 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "Helpers::LoadCursorW", (int *)v8);
  CursorW = LoadCursorW(hInstance, lpCursorName);
  if ( !CursorW )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    *(_DWORD *)v8 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Fu, &stru_10036F8, v8[0]);
  }
  if ( a3 )
    *(_DWORD *)a3 = *(_DWORD *)v8;
  Helpers::CLogBlock::~CLogBlock(v7);
  return CursorW;
}
