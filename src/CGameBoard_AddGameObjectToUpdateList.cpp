//----- (01008192) --------------------------------------------------------
void CGameBoard::AddGameObjectToUpdateList(CGameBoard *self, struct CGameObject *a2)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::AddGameObjectToUpdateList", 0);
  if ( *(int *)self < 300 )
    *((_DWORD *)self + ++*(_DWORD *)self) = (uint32)(uintptr_t)a2;
  ((Helpers::CLogBlock *)v3)->~CLogBlock();
}
