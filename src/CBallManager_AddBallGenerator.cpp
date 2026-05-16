//----- (01005187) --------------------------------------------------------
void CBallManager::AddBallGenerator(CBallManager *self, struct CBoardTile *a2)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBallManager::AddBallGenerator", 0);
  *((_DWORD *)self + (*((_DWORD *)self + 20))++ + 21) = (uint32)(uintptr_t)a2;
  ((Helpers::CLogBlock *)v3)->~CLogBlock();
}
