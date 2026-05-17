//----- (0100EB98) --------------------------------------------------------
int __thiscall CDisplay::UpdateBounds(CDisplay *this)
{
  bool v2; // zf
  _DWORD *v3; // ebx
  int v4; // eax
  int *SystemMetrics; // eax
  int v6; // eax
  int v7; // esi
  int v9; // [esp-4h] [ebp-2Ch]
  int *v10; // [esp+0h] [ebp-28h]
  _BYTE v11[8]; // [esp+10h] [ebp-18h] BYREF
  int v12[3]; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  v12[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::UpdateBounds", v12);
  v2 = *((_DWORD *)this + 12) == 0;
  v13 = 0;
  if ( v2 )
  {
    SystemMetrics = (int *)Helpers::GetSystemMetrics((Helpers *)1, 0, v10);
    v6 = Helpers::GetSystemMetrics(0, 0, SystemMetrics);
    SetRect((LPRECT)this + 2, 0, 0, v6, v9);
  }
  else
  {
    Helpers::GetClientRect(*((HWND *)this + 7), (HWND)this + 8, 0, v10);
    ClientToScreen(*((HWND *)this + 7), (LPPOINT)this + 4);
    v3 = (_DWORD *)((char *)this + 40);
    ClientToScreen(*((HWND *)this + 7), (LPPOINT)this + 5);
    v4 = *((_DWORD *)this + 8);
    if ( v4 > *((_DWORD *)this + 10) )
    {
      *((_DWORD *)this + 8) = *v3;
      *v3 = v4;
    }
  }
  v7 = v12[0];
  v13 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return v7;
}
