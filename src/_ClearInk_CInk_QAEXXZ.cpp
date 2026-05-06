void __thiscall CInk::ClearInk(CInk *this)
{
  int v1; // ecx
  _BYTE v2[8]; // [esp+10h] [ebp-1Ch] BYREF
  int v3; // [esp+18h] [ebp-14h] BYREF
  int v4[3]; // [esp+1Ch] [ebp-10h] BYREF
  int v5; // [esp+28h] [ebp-4h]

  v4[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CInk::ClearInk", v4);
  v1 = *(_DWORD *)g_pIInkObject;
  v5 = 0;
  v4[0] = (*(int (__stdcall **)(struct IInkObject *, int *))(v1 + 16))(g_pIInkObject, &v3);
  if ( v4[0] >= 0 )
    v4[0] = (*(int (__stdcall **)(struct IInkObject *, _DWORD, int))(*(_DWORD *)g_pIInkObject + 68))(
              g_pIInkObject,
              0,
              v3);
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
