#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    namespace Helpers {
        class CLogBlock {
        public:
            CLogBlock(void* buffer, const char* message, int);
            ~CLogBlock();
        };
        extern void* memset(void* dest, int value, size_t count);
    }
}

};

extern "C" void KillPlayer(int reason);
extern "C" BOARDHIST g_bhPrevBoards; // Global board history
extern "C" BOARDHIST g_bhPrevBonusBoards; // Global bonus board history
extern "C" int iBoardListCount; // Global board list count
extern "C" int iBonusBoardListCount; // Global bonus board list count
extern "C" int iNoviceBoardsCount; // Global novice boards count
extern "C" int iNoviceBonusBoardsCount; // Global novice bonus boards count
extern "C" int iBeginnerBoardsCount; // Global beginner boards count
extern "C" int iBeginnerBonusBoardsCount; // Global beginner bonus boards count
extern "C" int iIntermediateBoardsCount; // Global intermediate boards count
extern "C" int iIntermediateBonusBoardsCount; // Global intermediate bonus boards count
extern "C" int iAdvancedBoardsCount; // Global advanced boards count
extern "C" int iAdvancedBonusBoardsCount; // Global advanced bonus boards count
extern "C" int iExpertBoardsCount; // Global expert boards count
extern "C" int iExpertBonusBoardsCount; // Global expert bonus boards count
extern "C" void* paBoardList; // Global board list array
extern "C" void* paBonusBoardList; // Global bonus board list array
extern "C" BoardCollection g_aNoviceBoards; // Global novice boards
extern "C" BoardCollection g_aNoviceBonusBoards; // Global novice bonus boards
extern "C" BoardCollection g_aBeginnerBoards; // Global beginner boards
extern "C" BoardCollection g_aBeginnerBonusBoards; // Global beginner bonus boards
extern "C" BoardCollection g_aIntermediateBoards; // Global intermediate boards
extern "C" BoardCollection g_aIntermediateBonusBoards; // Global intermediate bonus boards
extern "C" BoardCollection g_aAdvancedBoards; // Global advanced boards
extern "C" BoardCollection g_aAdvancedBonusBoards; // Global advanced bonus boards
extern "C" BoardCollection g_aExpertBoards; // Global expert boards
extern "C" BoardCollection g_aExpertBonusBoards; // Global expert bonus boards

void __thiscall CBoardManager::SetDifficulty(CBoardManager *this, int difficulty)
{
    int bonus_board_count;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardManager::SetDifficulty", 0);
    flag = 0;
    
    KillPlayer(2);
    this->difficulty_level = difficulty;
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
        this->difficulty_level = 0;
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
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}

#endif
