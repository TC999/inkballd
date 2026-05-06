BOOL __stdcall CTabLicense::CanRunInkball()
{
  BOOL BOOLPermission; // eax
  BOOL v1; // esi
  const char *v3[4]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTabLicense::CanRunInkball", 0);
  v4 = 0;
  BOOLPermission = CTabLicense::GetBOOLPermission(L"TabletPCInkBall-EnableGame", 0);
  v4 = -1;
  v1 = BOOLPermission;
  Helpers::CLogBlock::~CLogBlock(v3);
  return v1;
}
