void __stdcall ReleaseInkBufferHDC(HDC a1)
{
  struct IDirectDrawSurface7 *InkBuffer; // eax
  _BYTE v2[8]; // [esp+10h] [ebp-18h] BYREF
  int v3[3]; // [esp+18h] [ebp-10h] BYREF
  int v4; // [esp+24h] [ebp-4h]

  v3[0] = -2147467259;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "ReleaseInkBufferHDC", v3);
  v4 = 0;
  InkBuffer = CDisplay::GetInkBuffer(g_pDisplay);
  if ( InkBuffer )
    v3[0] = InkBuffer->lpVtbl->ReleaseDC(InkBuffer, a1);
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
