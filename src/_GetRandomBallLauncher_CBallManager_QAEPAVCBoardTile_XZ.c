struct CBoardTile *__thiscall CBallManager::GetRandomBallLauncher(CBallManager *this)
{
  int v2; // esi
  int v4; // [esp-4h] [ebp-28h]
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBallManager::GetRandomBallLauncher", 0);
  v4 = *((_DWORD *)this + 20);
  v6 = 0;
  v2 = *((_DWORD *)this + GetRandomNumber(v4) + 21);
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return (struct CBoardTile *)v2;
}
