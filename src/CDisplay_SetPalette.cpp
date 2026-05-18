//----- (0100E796) --------------------------------------------------------
int CDisplay::SetPalette(void* self, struct IDirectDrawPalette *a2)
{
  int v3; // eax
  int v4; // esi
  _BYTE v6[8]; // [esp+10h] [ebp-18h] BYREF
  int v7[3]; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  v7[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CDisplay::SetPalette", v7);
  v8 = 0;
  if (*((_DWORD *)self + 2) )
    v3 = (*(int (__stdcall **)(_DWORD, struct IDirectDrawPalette *))(**((_DWORD **)self + 2) + 124))(*((_DWORD *)self + 2),
           a2);
  else
    v3 = -2147467261;
  v8 = -1;
  v4 = v3;
  v7[0] = v3;
  ((Helpers::CLogBlock *)v6)->~CLogBlock();
  return v4;
}
