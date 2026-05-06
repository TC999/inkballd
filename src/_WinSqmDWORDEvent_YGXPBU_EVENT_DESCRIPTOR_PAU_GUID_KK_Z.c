void __stdcall _WinSqmDWORDEvent(const struct _EVENT_DESCRIPTOR *a1, struct _GUID *a2, char a3, char a4)
{
  struct _GUID *v4; // eax
  _QWORD v5[6]; // [esp+8h] [ebp-30h] BYREF

  memset(v5, 0, sizeof(v5));
  if ( ((int (__stdcall *)(const struct _EVENT_DESCRIPTOR *, struct _GUID *))WinSqmEventEnabled)(a1, a2) )
  {
    v4 = a2;
    if ( !a2 )
      v4 = (struct _GUID *)&unk_105C840;
    v5[0] = (int)v4;
    v5[2] = (int)&a3;
    v5[4] = (int)&a4;
    v5[1] = 16;
    v5[3] = 4;
    v5[5] = 4;
    ((void (__stdcall *)(const struct _EVENT_DESCRIPTOR *, int, _QWORD *))WinSqmEventWrite)(a1, 3, v5);
  }
}
