int __thiscall CGameManager::Init(CGameManager *this)
{
  int v1; // eax
  int v2; // esi
  _BYTE v4[8]; // [esp+10h] [ebp-18h] BYREF
  int v5[3]; // [esp+18h] [ebp-10h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  v5[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameManager::Init", v5);
  v6 = 0;
  v1 = CGameBoard::Init(g_pCGameBoard);
  v6 = -1;
  v5[0] = v1;
  v2 = v1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
