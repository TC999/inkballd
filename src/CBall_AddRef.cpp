//----- (01003C23) --------------------------------------------------------
int CBall::AddRef(CBall* self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::AddRef", 0);
  v2 = ++*((_DWORD *)self + 34);
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return v2;
}
