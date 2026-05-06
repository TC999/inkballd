const unsigned __int8 *__thiscall CBoardManager::GetLastLoadedBoardData(CBoardManager *this)
{
  _BYTE v2[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CBoardManager::GetLastLoadedBoardData", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return (const unsigned __int8 *)&g_pLastLoadedLevel;
}
