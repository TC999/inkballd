LONG __stdcall CSink::Release(volatile LONG *this)
{
  LONG v1; // edi
  _BYTE v3[8]; // [esp+8h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CSink::Release", 0);
  v1 = InterlockedDecrement(this + 1);
  if ( !v1 )
    operator delete((void *)this);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return v1;
}
