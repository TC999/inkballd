#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern int32_t iBoardCounts;
extern int32_t iBeginnerBoardsCount;
extern int32_t iBeginnerBonusBoardsCount;
extern int32_t iNoviceBoardsCount;
extern int32_t iNoviceBonusBoardsCount;
extern int32_t iIntermediateBoardsCount;
extern int32_t iIntermediateBonusBoardsCount;
extern int32_t iAdvancedBoardsCount;
extern int32_t iAdvancedBonusBoardsCount;
extern int32_t iExpertBoardsCount;
extern int32_t iExpertBonusBoardsCount;

int32_t dword_10AF594;
int32_t dword_10AF598;
int32_t dword_10AF59C;
int32_t dword_10AF5A0;
int32_t dword_10AF5A4;
int32_t dword_10AF5A8;
int32_t dword_10AF5AC;
int32_t dword_10AF5B0;
int32_t dword_10AF5B4;

int dynamic_initializer_for__iBoardCounts__()
{
  int result; // eax

  iBoardCounts = iBeginnerBoardsCount;
  dword_10AF594 = iBeginnerBonusBoardsCount;
  dword_10AF598 = iNoviceBoardsCount;
  dword_10AF59C = iNoviceBonusBoardsCount;
  dword_10AF5A0 = iIntermediateBoardsCount;
  dword_10AF5A4 = iIntermediateBonusBoardsCount;
  dword_10AF5A8 = iAdvancedBoardsCount;
  dword_10AF5AC = iAdvancedBonusBoardsCount;
  dword_10AF5B0 = iExpertBoardsCount;
  result = iExpertBonusBoardsCount;
  dword_10AF5B4 = iExpertBonusBoardsCount;
  return result;
}
