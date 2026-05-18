//----- (0100E721) --------------------------------------------------------
int CDisplay::BltInk(void* self, struct tagRECT *a2)
{
  int v3; // ecx
  int v4; // esi
  _BYTE v6[8]; // [esp+10h] [ebp-18h] BYREF
  int v7[3]; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  v7[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CDisplay::BltInk", v7);
  v8 = 0;
  if (*((_DWORD *)self + 3) && (v3 = *((_DWORD *)self + 5)) != 0 )
  {
    v7[0] = (*(int (__stdcall **)(_DWORD, struct tagRECT *, int, struct tagRECT *, int, _DWORD))(**((_DWORD **)self + 3)
                                                                                               + 20))(*((_DWORD *)self + 3),
              a2,
              v3,
              a2,
              0x1000000,
              0);
    v4 = v7[0];
  }
  else
  {
    v4 = -2147467261;
    v7[0] = -2147467261;
  }
  v8 = -1;
  ((Helpers::CLogBlock *)v6)->~CLogBlock();
  return v4;
}
