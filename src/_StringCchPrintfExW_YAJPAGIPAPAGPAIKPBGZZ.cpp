int __usercall StringCchPrintfExW@<eax>(
        STRSAFE_LPWSTR *a1@<ebx>,
        unsigned __int16 *Buffer,
        unsigned int a3,
        unsigned __int16 **a4,
        unsigned int *a5,
        size_t cchOriginalDestLength,
        wchar_t *Format,
        ...)
{
  int v7; // esi
  unsigned int v9; // ebx
  int v10; // eax
  size_t *v12; // [esp+0h] [ebp-10h]
  DWORD v13; // [esp+4h] [ebp-Ch]
  size_t cbDest; // [esp+8h] [ebp-8h] BYREF
  unsigned int v15; // [esp+Ch] [ebp-4h]
  va_list Args; // [esp+30h] [ebp+20h] BYREF

  va_start(Args, Format);
  v7 = 0;
  if ( (cchOriginalDestLength & 0x100) != 0 )
  {
    if ( Buffer || !a3 )
    {
LABEL_6:
      if ( a3 <= 0x7FFFFFFF )
        goto LABEL_8;
    }
  }
  else
  {
    v7 = 0;
    if ( a3 )
      goto LABEL_6;
  }
  v7 = -2147024809;
LABEL_8:
  if ( v7 < 0 )
    return v7;
  cbDest = (size_t)Buffer;
  v15 = a3;
  if ( (cchOriginalDestLength & 0x100) != 0 && !Format )
    Format = (wchar_t *)dword_10035B8;
  v7 = 0;
  if ( (cchOriginalDestLength & 0xFFFFE000) != 0 )
  {
    v7 = -2147024809;
    if ( a3 )
      *Buffer = 0;
    goto LABEL_15;
  }
  if ( a3 )
  {
    v7 = 0;
    v9 = a3 - 1;
    v10 = __vsnwprintf(Buffer, a3 - 1, Format, Args);
    if ( v10 < 0 || v10 > v9 )
    {
      v7 = -2147024774;
    }
    else if ( v10 != v9 )
    {
      v9 = v10;
      goto LABEL_34;
    }
    Buffer[v9] = 0;
LABEL_34:
    cbDest = (size_t)&Buffer[v9];
    v15 = a3 - v9;
    if ( v7 >= 0 )
    {
      if ( (cchOriginalDestLength & 0x200) != 0 && v15 > 1 && 2 * v15 > 2 )
        memset((void *)(cbDest + 2), (unsigned __int8)cchOriginalDestLength, 2 * v15 - 2);
      goto LABEL_20;
    }
    goto LABEL_15;
  }
  if ( !*Format )
  {
LABEL_20:
    if ( a4 )
      *a4 = (unsigned __int16 *)cbDest;
    if ( a5 )
      *a5 = v15;
    return v7;
  }
  v7 = Buffer != 0 ? -2147024774 : -2147024809;
LABEL_15:
  if ( (cchOriginalDestLength & 0x1C00) != 0 && a3 )
    StringExHandleOtherFlagsW((STRSAFE_LPWSTR)(2 * a3), (size_t)&cbDest, cchOriginalDestLength, a1, v12, v13);
  if ( v7 >= 0 || v7 == -2147024774 )
    goto LABEL_20;
  return v7;
}
