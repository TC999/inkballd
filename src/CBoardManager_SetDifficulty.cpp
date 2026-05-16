//----- (01005CCB) --------------------------------------------------------
#include "global_types.h"
void __thiscall CBoardManager::SetDifficulty(int a2)
{
  int v3; // eax
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardManager::SetDifficulty", 0);
  v5 = 0;
  KillPlayer(2);
  ((_DWORD *)this)[33281] = a2;
  memset(&g_bhPrevBoards, 0, 0x2Cu);
  memset(&g_bhPrevBonusBoards, 0, 0x2Cu);
  if ( !a2 )
    goto LABEL_11;
  if ( a2 != 1 )
  {
    switch ( a2 )
    {
      case 2:
        iBoardListCount = iIntermediateBoardsCount;
        v3 = iIntermediateBonusBoardsCount;
        paBoardList = (struct BoardCollection *)&g_aIntermediateBoards;
        paBonusBoardList = (struct BoardCollection *)&g_aIntermediateBonusBoards;
        goto LABEL_12;
      case 3:
        iBoardListCount = iAdvancedBoardsCount;
        v3 = iAdvancedBonusBoardsCount;
        paBoardList = (struct BoardCollection *)&g_aAdvancedBoards;
        paBonusBoardList = (struct BoardCollection *)&g_aAdvancedBonusBoards;
        goto LABEL_12;
      case 4:
        iBoardListCount = iExpertBoardsCount;
        v3 = iExpertBonusBoardsCount;
        paBoardList = (struct BoardCollection *)&g_aExpertBoards;
        paBonusBoardList = (struct BoardCollection *)&g_aExpertBonusBoards;
        goto LABEL_12;
    }
    ((_DWORD *)this)[33281] = 0;
LABEL_11:
    iBoardListCount = iBeginnerBoardsCount;
    v3 = iBeginnerBonusBoardsCount;
    paBonusBoardList = (struct BoardCollection *)&g_aBeginnerBonusBoards;
    paBoardList = (struct BoardCollection *)&g_aBeginnerBoards;
    goto LABEL_12;
  }
  iBoardListCount = iNoviceBoardsCount;
  v3 = iNoviceBonusBoardsCount;
  paBoardList = (struct BoardCollection *)&g_aNoviceBoards;
  paBonusBoardList = (struct BoardCollection *)&g_aNoviceBonusBoards;
LABEL_12:
  v5 = -1;
  iBonusBoardListCount = v3;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
