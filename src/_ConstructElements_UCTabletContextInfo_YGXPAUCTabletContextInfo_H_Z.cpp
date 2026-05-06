unsigned int __stdcall ConstructElements<CTabletContextInfo>(_DWORD *a1, unsigned int a2)
{
  unsigned int v2; // ebx
  unsigned int result; // eax
  _DWORD *v4; // esi

  v2 = a2;
  result = 24 * a2;
  if ( is_mul_ok(0x18u, a2) && result != -1 )
  {
    v4 = a1;
    result = (unsigned int)memset(a1, 0, 24 * a2);
    while ( v2 )
    {
      --v2;
      if ( v4 )
      {
        *v4 = 0;
        v4[1] = 0;
        v4[2] = 0;
        v4[3] = 0;
        v4[4] = 0;
        v4[5] = 0;
      }
      v4 += 6;
    }
  }
  return result;
}
