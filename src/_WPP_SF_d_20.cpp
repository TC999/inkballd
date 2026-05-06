ULONG __stdcall WPP_SF_d(TRACEHANDLE LoggerHandle, USHORT MessageNumber, LPCGUID MessageGuid, char a4)
{
  return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, &a4, 4, 0);
}
