//----- (01005AAC) --------------------------------------------------------
#include "global_types.h"
int CBoardManager::LoadBoardFromResources(
        unsigned __int16 *a2,
        unsigned __int8 *a3,
        int *a4)
{
  int v4; // esi
  int v5; // edi
  _BYTE v7[16]; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBoardManager::LoadBoardFromResources", 0);
  v8 = 0;
  v4 = 0;
  v5 = 0;
  do
  {
    if ( v4 >= iBoardCollectionsCount )
      break;
    v5 = SearchBoardList(reinterpret_cast<wchar_t*>(a2), reinterpret_cast<uint8_t*>(a3), iBoardCounts[v4], *(&pBoardCollections + v4), a4);
    ++v4;
  }
  while ( !v5 );
  v8 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
  return v5;
}
