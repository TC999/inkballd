struct IDirectDrawSurface7 *__thiscall CDisplay::GetBoardBuffer(CDisplay *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetBoardBuffer", 0);
  v2 = *((_DWORD *)this + 6);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return (struct IDirectDrawSurface7 *)v2;
}
