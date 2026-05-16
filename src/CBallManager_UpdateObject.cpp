//----- (01005453) --------------------------------------------------------
void CBallManager::UpdateObject(CBallManager *self, unsigned int a2)
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
  v3 = *((_DWORD *)self + 321) == 0;
  v9 = 0;
  if ( !v3 )
  {
    CBallManager::UpdateBallList(self);
    CBallManager::InitBallPositions(self);
    *((_DWORD *)self + 321) = 0;
  }
  if ( *((int *)self + 10) <= 0 )
    goto LABEL_12;
  CBallManager::UpdateBallPositions(self, a2);
  *((_DWORD *)self + 322) -= a2;
  v4 = *((_DWORD *)self + 322);
  if ( v4 <= 800 )
  {
    *((_DWORD *)self + 12) += a2;
    if ( *((_DWORD *)self + 12) >= 0x64u )
    {
      v3 = *((_DWORD *)self + 13) == 0;
      *((_DWORD *)self + 12) = 0;
      *((_DWORD *)self + 13) = v3;
    }
  }
  if ( v4 <= 0 && *((int *)self + 20) > 0 )
  {
    RandomBallLauncher = CBallManager::GetRandomBallLauncher(self);
    if ( BallOnTile(RandomBallLauncher) )
    {
      *((_DWORD *)self + 322) = 0;
      goto LABEL_13;
    }
    v7 = *((_DWORD *)self + 9);
    *((_DWORD *)self + 9) = v7 + 1;
    Ball = GetBall(v7);
    CBallManager::SetBallOnLauncher(self, Ball, RandomBallLauncher);
    CBallManager::SetBallSpeed(self, Ball, -1.0);
    *((_DWORD *)Ball + 40) = 1;
    *((_DWORD *)Ball + 39) = 1;
    v6 = *((_DWORD *)self + 11);
    --*((_DWORD *)self + 10);
    *((_DWORD *)self + 13) = 0;
    *((_DWORD *)self + 322) = v6;
    CBallManager::UpdateBallList(self);
    if ( !*((_DWORD *)self + 323) )
    {
      *((_DWORD *)self + 323) = 1;
LABEL_12:
      StartTimer();
    }
  }
LABEL_13:
  (*(void (**)(CBallManager *))(*(_DWORD *)self + 4))(self);
  v9 = -1;
  ((Helpers::CLogBlock *)v8)->~CLogBlock();
}
