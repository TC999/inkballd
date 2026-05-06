int __stdcall CSink::SystemEvent(CSink *this, unsigned int a2, unsigned int a3, int a4, struct tagSYSTEM_EVENT_DATA a5)
{
  struct CTabletContextInfo *TabletContextInfo; // eax
  struct tagRECT *PlayingAreaRect; // eax
  _BYTE v8[8]; // [esp+4h] [ebp-Ch] BYREF
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CSink::SystemEvent", &v9);
  if ( (_WORD)a4 == 21 && g_tcid == a2 && g_cid == a3 )
  {
    TabletContextInfo = GetTabletContextInfo(g_tcid);
    if ( TabletContextInfo )
      (*(void (__stdcall **)(_DWORD, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)TabletContextInfo
                                                                                        + 36))(
        *(_DWORD *)TabletContextInfo,
        g_tcid,
        g_cid,
        0,
        0,
        0);
    if ( (*(int (__stdcall **)(struct IInkObject *, int *))(*(_DWORD *)g_pIInkObject + 16))(g_pIInkObject, &a4) >= 0
      && a4 )
    {
      (*(void (__stdcall **)(struct IInkObject *, int, int))(*(_DWORD *)g_pIInkObject + 68))(g_pIInkObject, a4 - 1, 1);
      BltBoardToInk(0);
      CInk::SetInkRedrawFlag(*((CInk **)g_pCGameBoard + 2481));
      PlayingAreaRect = CGameBoard::GetPlayingAreaRect(g_pCGameBoard);
      AddDisplayUpdateRect(PlayingAreaRect);
    }
  }
  v9 = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return 0;
}
