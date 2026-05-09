#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall CSink::CursorDown(
        CSink *this,
        struct IInkStroke *a2,
        uint32_t a3,
        uint32_t a4,
        uint32_t a5,
        unsigned __int8 *a6)
{
  struct IInkStroke *v6; // edi
  struct CTabletContextInfo *TabletContextInfo; // eax
  uint32_t v8; // ecx
  int v9; // esi
  uint32_t v11; // esi
  struct tagRECT *PlayingAreaRect; // eax
  uint32_t v13; // [esp-4h] [ebp-1Ch]
  char v14[8]; // [esp+Ch] [ebp-Ch] BYREF
  char v15[4]; // [esp+14h] [ebp-4h] BYREF

  *(uint32_t *)v15 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CSink::CursorDown", (int*)v15);
  v6 = a2;
  TabletContextInfo = GetTabletContextInfo((uint32_t)a2);
  if ( TabletContextInfo )
  {
    v8 = *((uint32_t *)TabletContextInfo + 4);
    if ( v8 < a5 >> 2 && (*(uint32_t *)&a6[4 * v8] & *((uint32_t *)TabletContextInfo + 5)) != 0 )
    {
      v9 = *(uint32_t *)v15;
      goto LABEL_5;
    }
  }
  if ( !AcceptInkInput() || g_tcid )
  {
LABEL_17:
    *(uint32_t *)v15 = 0;
    v9 = 0;
    goto LABEL_5;
  }
  v11 = a3;
  v13 = a3;
  *((uint32_t *)this + 2) = 1;
  SetCursorAttributes(v13);
  g_tcid = (uint32_t)v6;
  g_cid = v11;
  if ( (*(int (__stdcall **)(struct IInkObject *, CSink **))(*(uint32_t *)g_pIInkObject + 16))(g_pIInkObject, &this) >= 0
    && (uint32_t)this >= 0x14 )
  {
    (*(void (__stdcall **)(struct IInkObject *, uint32_t, char*))(*(uint32_t *)g_pIInkObject + 68))(
      g_pIInkObject,
      0,
      reinterpret_cast<char*>(this) - 19);
    BltBoardToInk(0);
    CInk::SetInkRedrawFlag(*((CInk **)g_pCGameBoard + 2481));
    PlayingAreaRect = CGameBoard::GetPlayingAreaRect(g_pCGameBoard);
    AddDisplayUpdateRect(PlayingAreaRect);
  }
  a2 = 0;
  *(uint32_t *)v15 = (*(int (__stdcall **)(struct IInkCollect *, struct IInkStroke *, uint32_t, struct IInkStroke **))(*(uint32_t *)g_pIInkCollect + 12))(
                     g_pIInkCollect,
                     v6,
                     v11,
                     &a2);
  if ( *(int*)v15 >= 0 )
  {
    SetCursorStroke(v11, a2);
    (*(void (__stdcall **)(struct IInkCollect *, uint32_t, uint32_t, unsigned __int8 *))(*(uint32_t *)g_pIInkCollect
                                                                                               + 16))(
      g_pIInkCollect,
      v11,
      a5,
      a6);
    goto LABEL_17;
  }
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x17u, &stru_1002480, v15[0]);
  *(uint32_t *)v15 = -2147467259;
  v9 = -2147467259;
LABEL_5:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v9;
}
