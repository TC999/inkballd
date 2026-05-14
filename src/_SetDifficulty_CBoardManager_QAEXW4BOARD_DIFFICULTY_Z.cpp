#include "global_types.h"
#include <cstdint>
#include <windows.h>
#include <new>

extern "C" {
    void KillPlayer(int reason);
}

void SetDifficulty_CBoardManager(CBoardManager* self, int difficulty)
{
    int bonus_board_count;
    uint8_t log_buffer[16];
    int flag;

    new (&log_buffer) Helpers::CLogBlock(&log_buffer, "CBoardManager::SetDifficulty", 0);
    flag = 0;
    
    KillPlayer(2);
    self->difficulty_level = difficulty;
    Helpers::memset(&g_bhPrevBoards, 0, 0x2C);
    Helpers::memset(&g_bhPrevBonusBoards, 0, 0x2C);
    
    if (difficulty == 0)
        goto LABEL_11;
    
    if (difficulty != 1)
    {
        switch (difficulty)
        {
            case 2:
                iBoardListCount = iIntermediateBoardsCount;
                bonus_board_count = iIntermediateBonusBoardsCount;
                paBoardList = &g_aIntermediateBoards;
                paBonusBoardList = &g_aIntermediateBonusBoards;
                goto LABEL_12;
            case 3:
                iBoardListCount = iAdvancedBoardsCount;
                bonus_board_count = iAdvancedBonusBoardsCount;
                paBoardList = &g_aAdvancedBoards;
                paBonusBoardList = &g_aAdvancedBonusBoards;
                goto LABEL_12;
            case 4:
                iBoardListCount = iExpertBoardsCount;
                bonus_board_count = iExpertBonusBoardsCount;
                paBoardList = &g_aExpertBoards;
                paBonusBoardList = &g_aExpertBonusBoards;
                goto LABEL_12;
        }
        self->difficulty_level = 0;
LABEL_11:
        iBoardListCount = iBeginnerBoardsCount;
        bonus_board_count = iBeginnerBonusBoardsCount;
        paBonusBoardList = &g_aBeginnerBonusBoards;
        paBoardList = &g_aBeginnerBoards;
        goto LABEL_12;
    }
    
    iBoardListCount = iNoviceBoardsCount;
    bonus_board_count = iNoviceBonusBoardsCount;
    paBoardList = &g_aNoviceBoards;
    paBonusBoardList = &g_aNoviceBonusBoards;
    
LABEL_12:
    flag = -1;
    iBonusBoardListCount = bonus_board_count;
    ((Helpers::CLogBlock*)&log_buffer)->~CLogBlock();
}
