//----- (01005453) --------------------------------------------------------
void __thiscall CBallManager::UpdateObject(CBallManager *this, unsigned int a2)
{
  bool v3; // zf
  int v4; // eax
  struct CBall *Ball; // edi
  int v6; // eax
  int v7; // [esp+4h] [ebp-28h]
  _BYTE v8[16]; // [esp+18h] [ebp-14h] BYREF
  int v9; // [esp+28h] [ebp-4h]
  struct CBoardTile *RandomBallLauncher; // [esp+34h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBallManager::UpdateObject", 0);
  v3 = *((_DWORD *)this + 321) == 0;
  v9 = 0;
  if ( !v3 )
  {
    CBallManager::UpdateBallList(this);
    CBallManager::InitBallPositions(this);
    *((_DWORD *)this + 321) = 0;
  }
  if ( *((int *)this + 10) <= 0 )
    goto LABEL_12;
  CBallManager::UpdateBallPositions(this, a2);
  *((_DWORD *)this + 322) -= a2;
  v4 = *((_DWORD *)this + 322);
  if ( v4 <= 800 )
  {
    *((_DWORD *)this + 12) += a2;
    if ( *((_DWORD *)this + 12) >= 0x64u )
    {
      v3 = *((_DWORD *)this + 13) == 0;
      *((_DWORD *)this + 12) = 0;
      *((_DWORD *)this + 13) = v3;
    }
  }
  if ( v4 <= 0 && *((int *)this + 20) > 0 )
  {
    RandomBallLauncher = CBallManager::GetRandomBallLauncher(this);
    if ( BallOnTile(RandomBallLauncher) )
    {
      *((_DWORD *)this + 322) = 0;
      goto LABEL_13;
    }
    v7 = *((_DWORD *)this + 9);
    *((_DWORD *)this + 9) = v7 + 1;
    Ball = GetBall(v7);
    CBallManager::SetBallOnLauncher(this, Ball, RandomBallLauncher);
    CBallManager::SetBallSpeed(this, Ball, -1.0);
    *((_DWORD *)Ball + 40) = 1;
    *((_DWORD *)Ball + 39) = 1;
    v6 = *((_DWORD *)this + 11);
    --*((_DWORD *)this + 10);
    *((_DWORD *)this + 13) = 0;
    *((_DWORD *)this + 322) = v6;
    CBallManager::UpdateBallList(this);
    if ( !*((_DWORD *)this + 323) )
    {
      *((_DWORD *)this + 323) = 1;
LABEL_12:
      StartTimer();
    }
  }
LABEL_13:
  (*(void (__thiscall **)(CBallManager *))(*(_DWORD *)this + 4))(this);
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
