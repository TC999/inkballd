//----- (0100A087) --------------------------------------------------------
void __thiscall CGameManager::UpdateTime(CGameManager *this)
{
  *(_DWORD *)this = timeGetTime();
}
