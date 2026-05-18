//----- (01006B30) --------------------------------------------------------
struct IDirectDraw7 *CDisplay::GetDirectDraw(void* self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetDirectDraw", 0);
  v2 = *((_DWORD *)self + 1);
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return (struct IDirectDraw7 *)v2;
}
