//----- (01008192) --------------------------------------------------------
void __thiscall CGameBoard::AddGameObjectToUpdateList(CGameBoard *self, struct CGameObject *a2)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::AddGameObjectToUpdateList", 0);
  if ( *(int *)self < 300 )
    *((_DWORD *)self + ++*(_DWORD *)self) = a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
