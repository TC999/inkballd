void __stdcall AddGameObjectToUpdateList(struct CGameObject *a1)
{
  _BYTE v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "AddGameObjectToUpdateList", 0);
  v2 = 0;
  CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, a1);
  v2 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
