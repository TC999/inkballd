ULONG __stdcall WPP_SF_(TRACEHANDLE LoggerHandle, USHORT MessageNumber, LPCGUID MessageGuid)
{
  return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, 0);
}
