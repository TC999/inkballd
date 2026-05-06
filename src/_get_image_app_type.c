int __cdecl _get_image_app_type(int a1)
{
  HMODULE ModuleHandleA; // eax
  int v2; // eax
  __int16 v3; // ax

  ModuleHandleA = GetModuleHandleA(0);
  if ( !ModuleHandleA )
    return a1;
  v2 = RtlpImageNtHeader((int)ModuleHandleA);
  if ( !v2 )
    return a1;
  v3 = *(_WORD *)(v2 + 92);
  if ( v3 == 2 )
    return 2;
  if ( v3 == 3 )
    return 1;
  else
    return a1;
}
