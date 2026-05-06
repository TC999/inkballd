int __stdcall EnableClassicWispWithPtr(LPVOID *ppv)
{
  int v1; // ebx
  _DWORD v3[2]; // [esp+Ch] [ebp-8h] BYREF

  v1 = 1;
  v3[0] = 0;
  v3[1] = 0;
  if ( CoCreateInstance(&CLSID_ClassicW, 0, 0x17u, &IID_IUnknown, ppv) < 0
    || (*(int (__stdcall **)(_DWORD, _DWORD *))(*(_DWORD *)*ppv + 12))(*ppv, v3) < 0
    || ((int (__stdcall *)(unsigned int, _DWORD, _DWORD, _DWORD))v3[0])(
         CLSID_EnablingKey.Data1,
         *(_DWORD *)&CLSID_EnablingKey.Data2,
         *(_DWORD *)CLSID_EnablingKey.Data4,
         *(_DWORD *)&CLSID_EnablingKey.Data4[4]) < 0 )
  {
    return 0;
  }
  return v1;
}
