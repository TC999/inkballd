struct IDirectDraw7 *__thiscall CDisplay::GetDirectDraw(CDisplay *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetDirectDraw", 0);
  v2 = *((_DWORD *)this + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return (struct IDirectDraw7 *)v2;
}
