CScoreManager *__thiscall CScoreManager::`scalar deleting destructor'(CScoreManager *this, char a2)
{
  CScoreManager::~CScoreManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
