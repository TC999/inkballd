HANDLE __stdcall Helpers::LoadImageW(
        HINSTANCE hInst,
        const WCHAR *name,
        UINT type,
        unsigned int a4,
        int cy,
        UINT fuLoad,
        _DWORD *a7,
        int *a8)
{
  HANDLE ImageW; // esi
  signed int LastError; // eax
  const char *v11[2]; // [esp+4h] [ebp-Ch] BYREF
  char v12[4]; // [esp+Ch] [ebp-4h] BYREF

  *(_DWORD *)v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "Helpers::LoadImageW", (int *)v12);
  ImageW = LoadImageW(hInst, name, type, a4, cy, fuLoad);
  if ( !ImageW )
  {
    LastError = GetLastError();
    if ( LastError > 0 )
      LastError = (unsigned __int16)LastError | 0x80070000;
    *(_DWORD *)v12 = LastError;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Du, &stru_10036F8, v12[0]);
  }
  if ( a7 )
    *a7 = *(_DWORD *)v12;
  Helpers::CLogBlock::~CLogBlock(v11);
  return ImageW;
}
