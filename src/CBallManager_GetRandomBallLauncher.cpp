//----- (010051BF) --------------------------------------------------------
CBoardTile *CBallManager::GetRandomBallLauncher(CBallManager *self)
{
  int v2; // esi
  int v4; // [esp-4h] [ebp-28h]
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBallManager::GetRandomBallLauncher", 0);
  v4 = *((_DWORD *)self + 20);
  v6 = 0;
  v2 = *((_DWORD *)self + GetRandomNumber(v4) + 21);
  v6 = -1;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
  return (struct CBoardTile *)v2;
}
