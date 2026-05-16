//----- (01004B72) --------------------------------------------------------
void CBall_dtor_raw(CBall* self)
{
  void **v2; // ecx
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  *(_DWORD *)self = (uint32_t)(uintptr_t)&CBall_vftable;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBall::~CBall", 0);
  v2 = (void **)*((_DWORD *)self + 30);
  v4 = 0;
  if ( v2 )
  {
    BallPoints::scalar_deleting_destructor((BallPoints*)v2, 1);
    *((_DWORD *)self + 30) = 0;
  }
  v4 = -1;
  ((Helpers::CLogBlock *)v3)->~CLogBlock();
}
