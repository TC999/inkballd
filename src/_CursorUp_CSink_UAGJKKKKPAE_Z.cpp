#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int CursorUp_CSink(CSink* self, int a1,
        int a2,
        HDC a4,
        uint32_t a5,
        uint32_t a6,
        uint32_t a7,
        unsigned __int8 *a8)
{
  uint32_t v8;
  unsigned __int8 *v10;
  char v12[8];
  char v13[4];

  *(uint32_t *)v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CSink::CursorUp", (int*)v13);
  if ( AcceptInkInput() )
  {
    if ( (HDC)g_tcid == a4 )
    {
      v8 = a5;
      if ( g_cid == a5 )
      {
        if ( *((uint32_t *)self + 2) )
        {
          v10 = a8;
          *((uint32_t *)self + 2) = 0;
          *(uint32_t *)v13 = (*(int (__stdcall **)(IInkCollect*, uint32_t, uint32_t, unsigned __int8 *, int, int))(*(uint32_t *)g_pIInkCollect + 16))(
                             g_pIInkCollect,
                             v8,
                             a7,
                             v10,
                             a2,
                             a1);
          if ( *(int*)v13 < 0
            && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
            && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x18u, &stru_1002480, v13[0]);
          }
          a4 = (HDC)0;
          GetInkBufferHDC(&a4);
          if ( a4 )
          {
            *(uint32_t *)v13 = (*(int (__stdcall **)(IRenderingContext*, uint32_t, HDC))(*(uint32_t *)g_pIRenderingContext + 36))(
                               g_pIRenderingContext,
                               v8,
                               a4);
            if ( *(int*)v13 < 0
              && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
              && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x19u, &stru_1002480, v13[0]);
            }
            ReleaseInkBufferHDC(a4);
          }
          *(uint32_t *)v13 = (*(int (__stdcall **)(IInkCollect*, uint32_t))(*(uint32_t *)g_pIInkCollect + 20))(
                             g_pIInkCollect,
                             v8);
          if ( *(int*)v13 < 0
            && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
            && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x1Au, &stru_1002480, v13[0]);
          }
          CInk::SetInkModifiedFlag(*((CInk **)g_pCGameBoard + 2481));
          g_tcid = 0;
          g_cid = -1;
        }
      }
    }
  }
  *(uint32_t *)v13 = 0;
  reinterpret_cast<Helpers::CLogBlock*>(v12)->~CLogBlock();
  return 0;
}
