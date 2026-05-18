//----- (01006BBA) --------------------------------------------------------
struct IDirectDrawSurface7 *CDisplay::GetInkBuffer(void* self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetInkBuffer", 0);
  v2 = *((_DWORD *)self + 5);
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return (struct IDirectDrawSurface7 *)v2;
}
