//----- (01010FF8) --------------------------------------------------------
CGameManager *__thiscall CGameManager::`scalar deleting destructor'(CGameManager *this, char a2)
{
  CGameManager::~CGameManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
