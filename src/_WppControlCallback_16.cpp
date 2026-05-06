ULONG __stdcall WppControlCallback(
        WMIDPREQUESTCODE RequestCode,
        _WORD *RequestContext,
        ULONG *BufferSize,
        PVOID Buffer)
{
  int v4; // edx
  _WORD *v6; // edi
  int v8; // ebx
  ULONG TraceEnableFlags; // eax
  TRACEHANDLE TraceLoggerHandle; // kr00_8
  __int16 v11; // cx
  _DWORD *v12; // ecx
  _WORD *v13; // esi
  UCHAR RequestContext_3; // [esp+23h] [ebp+Fh]

  v4 = 0;
  *BufferSize = 0;
  v6 = RequestContext;
  if ( RequestCode == WMI_ENABLE_EVENTS )
  {
    TraceLoggerHandle = GetTraceLoggerHandle(Buffer);
    v8 = TraceLoggerHandle;
    RequestContext_3 = GetTraceEnableLevel(TraceLoggerHandle);
    TraceEnableFlags = GetTraceEnableFlags(TraceLoggerHandle);
    v4 = HIDWORD(TraceLoggerHandle);
  }
  else
  {
    if ( RequestCode != WMI_DISABLE_EVENTS )
      return 87;
    v8 = 0;
    TraceEnableFlags = 0;
    RequestContext_3 = 0;
  }
  v11 = RequestContext[13];
  if ( (v11 & 1) != 0 && *((_DWORD *)RequestContext + 4) )
  {
    v12 = (_DWORD *)*((_DWORD *)RequestContext + 4);
    *v12 = v8;
    v12[1] = v4;
    *(_DWORD *)(*((_DWORD *)RequestContext + 4) + 12) = RequestContext_3;
    *(_DWORD *)(*((_DWORD *)RequestContext + 4) + 8) = TraceEnableFlags;
  }
  else
  {
    if ( (v11 & 2) != 0 )
    {
      v13 = (_WORD *)*((_DWORD *)RequestContext + 4);
      if ( v13 )
        v6 = v13;
    }
    *((_DWORD *)v6 + 4) = v8;
    *((_DWORD *)v6 + 5) = v4;
    *((_BYTE *)v6 + 25) = RequestContext_3;
    *((_DWORD *)v6 + 7) = TraceEnableFlags;
  }
  return 0;
}
