//----- (01006B5E) --------------------------------------------------------
struct IDirectDrawSurface7 *CDisplay::GetFrontBuffer(void* self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetFrontBuffer", 0);
  v2 = *((_DWORD *)self + 2);
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return (struct IDirectDrawSurface7 *)v2;
}
