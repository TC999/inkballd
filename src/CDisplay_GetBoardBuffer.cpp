//----- (01006BE8) --------------------------------------------------------
struct IDirectDrawSurface7 *CDisplay::GetBoardBuffer(void* self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetBoardBuffer", 0);
  v2 = *((_DWORD *)self + 6);
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return (struct IDirectDrawSurface7 *)v2;
}
