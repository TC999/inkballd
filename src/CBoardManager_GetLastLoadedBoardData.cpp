//----- (01005E13) --------------------------------------------------------
const unsigned __int8 *__thiscall CBoardManager::GetLastLoadedBoardData()
{
  _BYTE v2[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CBoardManager::GetLastLoadedBoardData", 0);
  reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
  return (const unsigned __int8 *)&g_pLastLoadedLevel;
}
