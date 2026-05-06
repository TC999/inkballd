ULONG __stdcall WPP_SF_Sd(
        TRACEHANDLE LoggerHandle,
        USHORT MessageNumber,
        LPCGUID MessageGuid,
        const unsigned __int16 *a4,
        char a5)
{
  const wchar_t *v5; // edx
  unsigned int v6; // eax
  int v8; // [esp-4h] [ebp-4h]

  v5 = a4;
  if ( a4 )
  {
    if ( *a4 )
    {
      v6 = 2 * wcslen(a4) + 2;
      goto LABEL_7;
    }
    v8 = 14;
  }
  else
  {
    v8 = 10;
  }
  v6 = v8;
LABEL_7:
  if ( a4 )
  {
    if ( !*a4 )
      v5 = L"<NULL>";
  }
  else
  {
    v5 = L"NULL";
  }
  return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, v5, v6, &a5, 4, 0);
}
