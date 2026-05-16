//----- (0100A087) --------------------------------------------------------
void CGameManager::UpdateTime(CGameManager *self)
{
  *(_DWORD *)self = timeGetTime();
}
