#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
bool CGameBoard::IsRemoteSession(CGameBoard *self)
{
  (void)self;
  return GetSystemMetrics(4096) != 0;
}
