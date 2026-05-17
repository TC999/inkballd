//----- (0100D1CB) --------------------------------------------------------
void CScoreManager::Restore(CScoreManager *self)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CScoreManager::Restore", 0);
  v4 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  DDrawSurface->lpVtbl->Restore(DDrawSurface);
  (*(void (**)(CScoreManager *))(*(_DWORD *)self + 4))(self);
  v4 = -1;
  ((Helpers::CLogBlock *)v3)->~CLogBlock();
}
