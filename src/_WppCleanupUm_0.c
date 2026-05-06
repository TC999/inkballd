void __stdcall WppCleanupUm()
{
  _QWORD *v0; // esi

  v0 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control )
  {
    while ( v0 )
    {
      if ( v0[1] )
      {
        UnregisterTraceGuids(v0[1]);
        *((_DWORD *)v0 + 2) = 0;
        *((_DWORD *)v0 + 3) = 0;
      }
      v0 = *(_QWORD **)v0;
    }
    WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
  }
}
