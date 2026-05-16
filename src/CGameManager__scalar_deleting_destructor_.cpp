//----- (01010FF8) --------------------------------------------------------
void CGameManager::scalar_deleting_destructor(CGameManager *self, char a2)
{
  self->~CGameManager();
  if ( (a2 & 1) != 0 )
    operator delete(self);
}
