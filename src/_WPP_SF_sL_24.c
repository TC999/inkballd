ULONG __stdcall WPP_SF_sL(TRACEHANDLE LoggerHandle, USHORT MessageNumber, LPCGUID MessageGuid, const char *a4, char a5)
{
  unsigned int v5; // eax
  const char *v6; // ecx

  if ( a4 )
    v5 = strlen(a4) + 1;
  else
    v5 = 5;
  v6 = a4;
  if ( !a4 )
    v6 = "NULL";
  return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, v6, v5, &a5, 4, 0);
}
