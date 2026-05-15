//----- (0100C27B) --------------------------------------------------------
void __thiscall CInk::OnDisplayChange(CInk *self)
{
  int v1; // esi
  int v2; // edi
  _BYTE v3[16]; // [esp+10h] [ebp-28h] BYREF
  _BYTE v4[8]; // [esp+20h] [ebp-18h] BYREF
  int v5[3]; // [esp+28h] [ebp-10h] BYREF
  int v6; // [esp+34h] [ebp-4h]

  v1 = 0;
  v5[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CInk::OnDisplayChange", v5);
  v6 = 0;
  if ( dword_10B068C > 0 )
  {
    v2 = dword_10B068C;
    do
    {
      v5[0] = (*(int (__stdcall **)(_DWORD, _BYTE *))(**(_DWORD **)((char *)g_arrTCI + v1 + 4) + 56))(
                *(_DWORD *)((char *)g_arrTCI + v1 + 4),
                v3);
      if ( v5[0] >= 0 )
        v5[0] = (*(int (__stdcall **)(struct IInkObject *, _DWORD, _BYTE *, void *))(*(_DWORD *)g_pIInkObject + 132))(
                  g_pIInkObject,
                  *(_DWORD *)((char *)g_arrTCI + v1 + 8),
                  v3,
                  &g_rcTabletInInk);
      v1 += 24;
      --v2;
    }
    while ( v2 );
  }
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
