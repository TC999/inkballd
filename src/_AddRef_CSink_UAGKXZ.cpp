LONG __stdcall CSink::AddRef(volatile LONG *this)
{
  LONG v1; // esi
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CSink::AddRef", 0);
  v1 = InterlockedIncrement(this + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return v1;
}
