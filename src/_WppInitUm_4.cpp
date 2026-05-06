ULONG __stdcall WppInitUm(int a1)
{
  ULONG64 *v1; // esi
  const GUID **v2; // edi
  const GUID *v3; // eax
  ULONG result; // eax
  _TRACE_GUID_REGISTRATION TraceGuidReg; // [esp+8h] [ebp-8h] BYREF

  v1 = (ULONG64 *)WPP_GLOBAL_Control;
  v2 = (const GUID **)&WPP_REGISTRATION_GUIDS;
  while ( v1 )
  {
    v3 = *v2;
    TraceGuidReg.RegHandle = 0;
    ++v2;
    TraceGuidReg.Guid = v3;
    result = RegisterTraceGuidsW((WMIDPREQUEST)WppControlCallback, v1, v3, 1u, &TraceGuidReg, 0, 0, v1 + 1);
    v1 = *(ULONG64 **)v1;
  }
  return result;
}
