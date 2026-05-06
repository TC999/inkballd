int __stdcall WPP_INIT_CONTROL_ARRAY(int a1)
{
  int result; // eax

  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)a1 = &unk_10B26E0;
  *(_BYTE *)(a1 + 24) = 1;
  *(_BYTE *)(a1 + 25) = 2;
  *(_WORD *)(a1 + 26) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  result = a1 + 32;
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_BYTE *)(a1 + 56) = 1;
  *(_BYTE *)(a1 + 57) = 2;
  *(_WORD *)(a1 + 58) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  return result;
}
