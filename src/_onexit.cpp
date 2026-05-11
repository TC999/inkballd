#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
_onexit_t __cdecl _onexit(_onexit_t Func)
{
  int (__cdecl *v2)(); // [esp+10h] [ebp-24h]
  int v3; // [esp+14h] [ebp-20h] BYREF
  int v4; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  v4 = __onexitbegin;
  if ( __onexitbegin == -1 )
    return __onexit(Func);
  ((void (__cdecl *)(int))_lock)(8);
  ms_exc.registration.TryLevel = 0;
  v4 = __onexitbegin;
  v3 = __onexitend;
  v2 = (int (__cdecl *)())((int (__cdecl *)(_onexit_t, int*, int*))__dllonexit)(Func, &v4, &v3);
  __onexitbegin = v4;
  __onexitend = v3;
  ms_exc.registration.TryLevel = -2;
  ((void (__cdecl *)(int))_unlock)(8);
  return v2;
}

#endif
