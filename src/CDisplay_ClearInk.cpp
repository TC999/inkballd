//----- (0100E6B4) --------------------------------------------------------
int CDisplay::ClearInk(void* self, struct tagRECT *a2, int a3)
{
  int v4; // eax
  int v5; // esi
  _BYTE v7[8]; // [esp+10h] [ebp-18h] BYREF
  int v8[3]; // [esp+18h] [ebp-10h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  v8[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CDisplay::ClearInk", v8);
  v9 = 0;
  if (*((_DWORD *)self + 5) )
    v4 = (*(int (__stdcall **)(_DWORD, struct tagRECT *, _DWORD, struct tagRECT *, int, _DWORD))(**((_DWORD **)self + 5)
                                                                                               + 20))(*((_DWORD *)self + 5),
           a2,
           *((_DWORD *)self + 6),
           a2,
           0x1000000,
           0);
  else
    v4 = -2147467261;
  v9 = -1;
  v5 = v4;
  v8[0] = v4;
  ((Helpers::CLogBlock *)v7)->~CLogBlock();
  return v5;
}
