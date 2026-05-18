//----- (01006B8C) --------------------------------------------------------
struct IDirectDrawSurface7 *CDisplay::GetBackBuffer(void* self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetBackBuffer", 0);
  v2 = *((_DWORD *)self + 3);
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return (struct IDirectDrawSurface7 *)v2;
}
