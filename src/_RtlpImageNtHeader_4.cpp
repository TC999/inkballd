int __stdcall RtlpImageNtHeader(int a1)
{
  int result; // eax
  unsigned int v2; // edx

  result = 0;
  if ( a1 )
  {
    if ( a1 != -1 && *(_WORD *)a1 == 23117 )
    {
      v2 = *(_DWORD *)(a1 + 60);
      if ( v2 < 0x10000000 )
      {
        result = v2 + a1;
        if ( *(_DWORD *)(v2 + a1) != 17744 )
          return 0;
      }
    }
  }
  return result;
}
