#include "global_types.h"
#include <cstdint>

extern BOOL CTabLicense_GetBOOLPermission(const wchar_t* name, int param);

static BOOL CTabLicense_CanRunInkball()
{
  BOOL BOOLPermission;
  BOOL v1;
  uint8_t v3[16];
  int v4;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CTabLicense::CanRunInkball", 0);
  v4 = 0;
  BOOLPermission = CTabLicense_GetBOOLPermission(L"TabletPCInkBall-EnableGame", 0);
  v4 = -1;
  v1 = BOOLPermission;
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
  return v1;
}
