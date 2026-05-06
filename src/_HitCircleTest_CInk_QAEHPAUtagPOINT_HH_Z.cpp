int __thiscall CInk::HitCircleTest(CInk *this, struct tagPOINT *a2, int a3, int a4)
{
  int v5; // ecx
  struct CTabletContextInfo *TabletContextInfo; // eax
  _BYTE v8[8]; // [esp+5Ch] [ebp-34h] BYREF
  _DWORD v9[2]; // [esp+64h] [ebp-2Ch] BYREF
  _DWORD v10[2]; // [esp+6Ch] [ebp-24h] BYREF
  int v11; // [esp+74h] [ebp-1Ch] BYREF
  int v12; // [esp+78h] [ebp-18h]
  int v13; // [esp+7Ch] [ebp-14h] BYREF
  _DWORD v14[3]; // [esp+80h] [ebp-10h] BYREF
  int v15; // [esp+8Ch] [ebp-4h]
  int v16; // [esp+98h] [ebp+8h]
  float v17; // [esp+9Ch] [ebp+Ch]

  v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CInk::HitCircleTest", &v13);
  v5 = 10 * a2->x;
  v10[1] = 10 * a2->y;
  v15 = 0;
  v14[0] = 0;
  v10[0] = v5;
  if ( a3 == 1 )
    v16 = 1;
  else
    v16 = 10 * a3;
  v17 = (float)v16;
  v13 = (*(int (__stdcall **)(struct IInkObject *, _DWORD *, float, _DWORD *))(*(_DWORD *)g_pIInkObject + 108))(
          g_pIInkObject,
          v10,
          COERCE_FLOAT(LODWORD(v17)),
          v14);
  if ( v13 )
  {
    v12 = 0;
  }
  else
  {
    v12 = 1;
    if ( a4 )
    {
      SetBoardActiveState(0);
      (*(void (__stdcall **)(struct IInkObject *, int *))(*(_DWORD *)g_pIInkObject + 16))(g_pIInkObject, &v11);
      v13 = (*(int (__stdcall **)(_DWORD, _DWORD, int, _DWORD *))(*(_DWORD *)v14[0] + 16))(v14[0], 0, 1, v9);
      if ( v13 < 0 || (v16 = 1, v9[0] != v11 - 1) )
        v16 = 0;
    }
    if ( v14[0] )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14[0] + 8))(v14[0]);
      v14[0] = 0;
    }
    if ( a4 )
    {
      if ( v16 )
      {
        TabletContextInfo = GetTabletContextInfo(g_tcid);
        if ( TabletContextInfo )
        {
          (*(void (__stdcall **)(_DWORD, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)TabletContextInfo
                                                                                            + 36))(
            *(_DWORD *)TabletContextInfo,
            g_tcid,
            g_cid,
            0,
            0,
            0);
          *((_DWORD *)this + 4) = 0;
        }
      }
      v13 = (*(int (__stdcall **)(struct IInkObject *, _DWORD *, float, _DWORD *))(*(_DWORD *)g_pIInkObject + 108))(
              g_pIInkObject,
              v10,
              COERCE_FLOAT(LODWORD(v17)),
              v14);
      if ( !v13 )
      {
        if ( (*(int (__stdcall **)(_DWORD, _DWORD, int, _DWORD *))(*(_DWORD *)v14[0] + 16))(v14[0], 0, 1, v9) >= 0 )
          (*(void (__stdcall **)(struct IInkObject *, _DWORD, int))(*(_DWORD *)g_pIInkObject + 68))(
            g_pIInkObject,
            v9[0],
            1);
        if ( v14[0] )
        {
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v14[0] + 8))(v14[0]);
          v14[0] = 0;
        }
      }
      BltBoardToInk(0);
      *((_DWORD *)this + 4) = 1;
      CInk::DrawInkToSurface(this, 0);
      SetBoardActiveState(1);
    }
  }
  v15 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v12;
}
