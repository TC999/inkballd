//----- (0100E4C4) --------------------------------------------------------
int CDisplay::Blt(
        void* self,
        unsigned int a2,
        unsigned int a3,
        void* a4,
        struct tagRECT *a5,
        unsigned int a6)
{
  int v7; // eax
  int v8; // esi
  _BYTE v10[8]; // [esp+10h] [ebp-18h] BYREF
  int v11[3]; // [esp+18h] [ebp-10h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  v11[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CDisplay::Blt", v11);
  v12 = 0;
  if (*((_DWORD *)self + 3) )
    v7 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, void*, struct tagRECT *, unsigned int))(**((_DWORD **)self + 3) + 28))(*((_DWORD *)self + 3),
           a2,
           a3,
           a4,
           a5,
           a6);
  else
    v7 = -2147467261;
  v12 = -1;
  v8 = v7;
  v11[0] = v7;
  ((Helpers::CLogBlock *)v10)->~CLogBlock();
  return v8;
}
