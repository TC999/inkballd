//----- (010089DE) --------------------------------------------------------
int __thiscall CGameBoard::InitDirectDraw(CGameBoard *self)
{
  int v2; // esi
  char *v3; // ecx
  CDisplay *v4; // eax
  struct IDirectDrawSurface7 *InkBuffer; // eax
  int *v7; // [esp+0h] [ebp-2C0h]
  int *v8; // [esp+0h] [ebp-2C0h]
  const char *v9[3]; // [esp+10h] [ebp-2B0h] BYREF
  _DWORD v10[3]; // [esp+1Ch] [ebp-2A4h] BYREF
  int WindowedDisplay; // [esp+28h] [ebp-298h] BYREF
  WCHAR Text[256]; // [esp+2Ch] [ebp-294h] BYREF
  WCHAR Caption[72]; // [esp+22Ch] [ebp-94h] BYREF
  int v14; // [esp+2BCh] [ebp-4h]

  v2 = 0;
  v10[2] = self;
  WindowedDisplay = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameBoard::InitDirectDraw", &WindowedDisplay);
  v14 = 1;
  v3 = (char *)operator new(0x38u);
  v9[2] = v3;
  LOBYTE(v14) = 2;
  if ( v3 )
    v4 = CDisplay::CDisplay((CDisplay *)v3);
  else
    v4 = 0;
  g_pDisplay = v4;
  v14 = 0;
  if ( !v4 )
    WindowedDisplay = -2147024882;
  if ( WindowedDisplay < 0 )
    goto LABEL_11;
  WindowedDisplay = CDisplay::CreateWindowedDisplay(
                      (LPVOID *)v4,
                      *((HWND *)self + 2480),
                      *((_DWORD *)self + 2465),
                      *((_DWORD *)self + 2466));
  if ( WindowedDisplay >= 0 )
    goto LABEL_16;
  if ( g_pDisplay )
  {
    CDisplay::scalar_deleting_destructor(g_pDisplay, 1);
    g_pDisplay = 0;
  }
  if ( WindowedDisplay >= 0 )
  {
LABEL_16:
    v10[0] = CDisplay::ConvertGDIColor(g_pDisplay, 0x10101u);
    v10[1] = CDisplay::ConvertGDIColor(g_pDisplay, 0xFFFFFFu);
    InkBuffer = CDisplay::GetInkBuffer(g_pDisplay);
    InkBuffer->lpVtbl->SetColorKey(InkBuffer, 2, (LPDDCOLORKEY)v10);
    WindowedDisplay = 0;
  }
  else
  {
LABEL_11:
    memset(Caption, 0, 128);
    memset(Text, 0, sizeof(Text));
    Helpers::LoadStringW(0, 0x3AA3u, Caption, (unsigned __int16 *)0x40, 0, v7);
    if ( CGameBoard::IsRemoteSession(self) == 1 )
      Helpers::LoadStringW(0, 0x3AABu, Text, (unsigned __int16 *)0x100, 0, v8);
    else
      Helpers::LoadStringW(0, 0x3AA5u, Text, (unsigned __int16 *)0x100, 0, v8);
    MessageBoxW(*((HWND *)self + 2480), Text, Caption, 0x10u);
    v2 = WindowedDisplay;
  }
  v14 = -1;
  Helpers::CLogBlock::~CLogBlock(v9);
  return v2;
}
