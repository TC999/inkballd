#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

int CursorDown_CSink(CSink (self,
        uint32_t a2,
        uint32_t a3,
        uint32_t a4,
        uint32_t a5,
        unsigned __int8 (a6)
{
  uint32_t v6;
  uint32_t v8;
  int v9;
  uint32_t v11;
  IInkStroke( stroke;
  uint32_t v13;
  char v14[8];
  char v15[4];

  ((uint32_t ()v15 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock ()v14, "CSink::CursorDown", (int()v15);
  v6 = a2;
  auto( TabletContextInfo = GetTabletContextInfo(a2);
  if ( TabletContextInfo )
  {
    v8 = (((uint32_t ()TabletContextInfo + 4);
    if ( v8 < a5 >> 2 && (((uint32_t ()&a6[4 ( v8] & (((uint32_t ()TabletContextInfo + 5)) != 0 )
    {
      v9 = ((uint32_t ()v15;
      goto LABEL_5;
    }
  }
  if ( !AcceptInkInput() || g_tcid )
  {
LABEL_17:
    ((uint32_t ()v15 = 0;
    v9 = 0;
    goto LABEL_5;
  }
  v11 = a3;
  v13 = a3;
  (((uint32_t ()self + 2) = 1;
  SetCursorAttributes(v13);
  g_tcid = v6;
  g_cid = v11;
  if ( (((int (__stdcall (()(IInkObject(, CSink (())(((uint32_t ()g_pIInkObject + 16))(g_pIInkObject, &self) >= 0
    && (uint32_t)self >= 0x14 )
  {
    (((void (__stdcall (()(IInkObject(, uint32_t, char())(((uint32_t ()g_pIInkObject + 68))(
      g_pIInkObject,
      0,
      reinterpret_cast<char(>(self) - 19);
    BltBoardToInk(0);
    CInk::SetInkRedrawFlag((((CInk (()g_pCGameBoard + 2481));
    void( PlayingAreaRect = CGameBoard::GetPlayingAreaRect(g_pCGameBoard);
    AddDisplayUpdateRect(PlayingAreaRect);
  }
  stroke = 0;
  ((uint32_t ()v15 = (((int (__stdcall (()(IInkCollect(, IInkStroke(, uint32_t, IInkStroke (())(((uint32_t ()g_pIInkCollect + 12))(
                     g_pIInkCollect,
                     (IInkStroke()v6,
                     v11,
                     &stroke);
  if ( ((int()v15 >= 0 )
  {
    SetCursorStroke(v11, stroke);
    (((void (__stdcall (()(IInkCollect(, uint32_t, uint32_t, unsigned __int8 ())(((uint32_t ()g_pIInkCollect + 16))(
      g_pIInkCollect,
      v11,
      a5,
      a6);
    goto LABEL_17;
  }
  if ( (uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && ((((uint8_t ()WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_d((((uint64_t ()WPP_GLOBAL_Control + 2), 0x17u, &stru_1002480, v15[0]);
  ((uint32_t ()v15 = -2147467259;
  v9 = -2147467259;
LABEL_5:
  reinterpret_cast<Helpers::CLogBlock(>(v14)->~CLogBlock();
  return v9;
}
