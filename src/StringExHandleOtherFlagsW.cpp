HRESULT __stdcall StringExHandleOtherFlagsW(
        STRSAFE_LPWSTR pszDest,
        size_t cbDest,
        size_t cchOriginalDestLength,
        STRSAFE_LPWSTR *ppszDestEnd,
        size_t *pcchRemaining,
        DWORD dwFlags)
{
  int v6; // ecx
  unsigned int *v7; // ebx
  _WORD *v8; // edi
  unsigned int v9; // esi
  _WORD *v10; // eax
  _WORD *v11; // eax

  v9 = (unsigned int)pszDest >> 1;
  if ( (unsigned int)pszDest >> 1 && (cchOriginalDestLength & 0x1000) != 0 )
  {
    v10 = &v8[v6];
    *(_DWORD *)cbDest = v10;
    *v7 = v9 - v6;
    *v10 = 0;
  }
  if ( (cchOriginalDestLength & 0x400) != 0 )
  {
    memset(v8, (unsigned __int8)cchOriginalDestLength, (size_t)pszDest);
    if ( (_BYTE)cchOriginalDestLength )
    {
      if ( !v9 )
        return 0;
      v11 = &v8[v9 - 1];
      *(_DWORD *)cbDest = v11;
      *v7 = 1;
      *v11 = 0;
    }
    else
    {
      *(_DWORD *)cbDest = v8;
      *v7 = v9;
    }
  }
  if ( v9 && (cchOriginalDestLength & 0x800) != 0 )
  {
    *(_DWORD *)cbDest = v8;
    *v7 = v9;
    *v8 = 0;
  }
  return 0;
}
