//----- (0100EB98) --------------------------------------------------------
int CDisplay::UpdateBounds(void* self)
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
  v2 = *((_DWORD *)self + 12) == 0;
  v13 = 0;
  if ( v2 )
  {
    SystemMetrics = (int *)Helpers::GetSystemMetrics((void*)1, 0, v10);
    v6 = Helpers::GetSystemMetrics(0, 0, SystemMetrics);
    SetRect((LPRECT)((uint8_t*)self + 8), 0, 0, v6, v9);
  }
  else
  {
    Helpers::GetClientRect(*((HWND *)self + 7), (RECT*)((uint8_t*)self + 32), 0, (int*)v10);
    ClientToScreen(*((HWND *)self + 7), (LPPOINT)((uint8_t*)self + 32));
    v3 = (_DWORD *)((char *)self + 40);
    ClientToScreen(*((HWND *)self + 7), (LPPOINT)((uint8_t*)self + 40));
    v4 = *((_DWORD *)self + 8);
    if ( v4 > *((_DWORD *)self + 10) )
    {
      *((_DWORD *)self + 8) = *v3;
      *v3 = v4;
    }
  }
  v7 = v12[0];
  v13 = -1;
  ((Helpers::CLogBlock *)v11)->~CLogBlock();
  return v7;
}
