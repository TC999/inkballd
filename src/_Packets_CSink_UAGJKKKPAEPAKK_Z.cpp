#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall CSink::Packets(
        CSink *this,
        HDC a2,
        uint32_t a3,
        uint32_t a4,
        unsigned __int8 *a5,
        uint32_t *a6,
        uint32_t a7)
{
  uint32_t v7; // esi
  int v8; // esi
  uint8_t v10[8]; // [esp+4h] [ebp-Ch] BYREF
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CSink::Packets", &v11);
  if ( !AcceptInkInput() )
    goto LABEL_9;
  if ( (HDC)g_tcid != a2 )
    goto LABEL_9;
  v7 = a7;
  if ( g_cid != a7 || !*((uint32_t *)this + 2) )
    goto LABEL_9;
  CInk::SetInkModifiedFlag(*((CInk **)g_pCGameBoard + 2481));
  v11 = (*(int (__stdcall **)(struct IInkCollect *, uint32_t, uint32_t, unsigned __int8 *))(*(uint32_t *)g_pIInkCollect
                                                                                                  + 16))(
          g_pIInkCollect,
          v7,
          a4,
          a5);
  if ( v11 >= 0 )
  {
    GetInkBufferHDC(&a2);
    v11 = (*(int (__stdcall **)(struct IRenderingContext *, uint32_t, HDC))(*(uint32_t *)g_pIRenderingContext + 36))(
            g_pIRenderingContext,
            v7,
            a2);
    ReleaseInkBufferHDC(a2);
LABEL_9:
    v11 = 0;
    v8 = 0;
    goto LABEL_7;
  }
  v11 = -2147467259;
  v8 = -2147467259;
LABEL_7:
  reinterpret_cast<Helpers::CLogBlock*>(v10)->~CLogBlock();
  return v8;
}

#endif
