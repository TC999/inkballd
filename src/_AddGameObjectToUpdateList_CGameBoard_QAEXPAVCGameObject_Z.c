void __thiscall CGameBoard::AddGameObjectToUpdateList(CGameBoard *this, struct CGameObject *a2)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::AddGameObjectToUpdateList", 0);
  if ( *(int *)this < 300 )
    *((_DWORD *)this + ++*(_DWORD *)this) = a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
