#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __cdecl __noreturn new_oom_handler()
{
  uint8_t pExceptionObject[12]; // [esp+10h] [ebp-20h] BYREF
  uint8_t v1[16]; // [esp+1Ch] [ebp-14h] BYREF
  int v2; // [esp+2Ch] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "new_oom_handler", 0);
  v2 = 0;
  std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject);
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
}
