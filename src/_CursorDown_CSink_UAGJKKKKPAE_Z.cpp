int __stdcall CSink::CursorDown(
        CSink *this,
        struct IInkStroke *a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned __int8 *a6)
{
  struct IInkStroke *v6; // edi
  struct CTabletContextInfo *TabletContextInfo; // eax
  unsigned int v8; // ecx
  int v9; // esi
  unsigned int v11; // esi
  struct tagRECT *PlayingAreaRect; // eax
  unsigned int v13; // [esp-4h] [ebp-1Ch]
  char v14[8]; // [esp+Ch] [ebp-Ch] BYREF
  char v15[4]; // [esp+14h] [ebp-4h] BYREF

  *(_DWORD *)v15 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CSink::CursorDown", (int *)v15);
  v6 = a2;
  TabletContextInfo = GetTabletContextInfo((unsigned int)a2);
  if ( TabletContextInfo )
  {
    v8 = *((_DWORD *)TabletContextInfo + 4);
    if ( v8 < a5 >> 2 && (*(_DWORD *)&a6[4 * v8] & *((_DWORD *)TabletContextInfo + 5)) != 0 )
    {
      v9 = *(_DWORD *)v15;
      goto LABEL_5;
    }
  }
  if ( !AcceptInkInput() || g_tcid )
  {
LABEL_17:
    *(_DWORD *)v15 = 0;
    v9 = 0;
    goto LABEL_5;
  }
  v11 = a3;
  v13 = a3;
  *((_DWORD *)this + 2) = 1;
  SetCursorAttributes(v13);
  g_tcid = (unsigned int)v6;
  g_cid = v11;
  if ( (*(int (__stdcall **)(struct IInkObject *, CSink **))(*(_DWORD *)g_pIInkObject + 16))(g_pIInkObject, &this) >= 0
    && (unsigned int)this >= 0x14 )
  {
    (*(void (__stdcall **)(struct IInkObject *, _DWORD, char *))(*(_DWORD *)g_pIInkObject + 68))(
      g_pIInkObject,
      0,
      (char *)this - 19);
    BltBoardToInk(0);
    CInk::SetInkRedrawFlag(*((CInk **)g_pCGameBoard + 2481));
    PlayingAreaRect = CGameBoard::GetPlayingAreaRect(g_pCGameBoard);
    AddDisplayUpdateRect(PlayingAreaRect);
  }
  a2 = 0;
  *(_DWORD *)v15 = (*(int (__stdcall **)(struct IInkCollect *, struct IInkStroke *, unsigned int, struct IInkStroke **))(*(_DWORD *)g_pIInkCollect + 12))(
                     g_pIInkCollect,
                     v6,
                     v11,
                     &a2);
  if ( *(int *)v15 >= 0 )
  {
    SetCursorStroke(v11, a2);
    (*(void (__stdcall **)(struct IInkCollect *, unsigned int, unsigned int, unsigned __int8 *))(*(_DWORD *)g_pIInkCollect
                                                                                               + 16))(
      g_pIInkCollect,
      v11,
      a5,
      a6);
    goto LABEL_17;
  }
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x17u, &stru_1002480, v15[0]);
  *(_DWORD *)v15 = -2147467259;
  v9 = -2147467259;
LABEL_5:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v9;
}
