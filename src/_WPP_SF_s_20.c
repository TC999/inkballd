ULONG __stdcall WPP_SF_s(TRACEHANDLE LoggerHandle, USHORT MessageNumber, LPCGUID MessageGuid, const char *a4)
{
  unsigned int v4; // eax
  const char *v5; // ecx

  if ( a4 )
    v4 = strlen(a4) + 1;
  else
    v4 = 5;
  v5 = a4;
  if ( !a4 )
    v5 = "NULL";
  return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, v5, v4, 0);
}
