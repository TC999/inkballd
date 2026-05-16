//----- (01004BE8) --------------------------------------------------------
int CBall::Release(CBall* self)
{
  bool v2; // zf
  int v3; // edi
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::Release", 0);
  v6 = 0;
  v2 = (*((_DWORD *)self + 34))-- == 1;
  v3 = *((_DWORD *)self + 34);
  if ( v2 )
    CBall::scalar_deleting_destructor(self, 1);
  v6 = -1;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
  return v3;
}
