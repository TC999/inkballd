int __userpurge CSink::CursorUp@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        CSink *this,
        HDC a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned __int8 *a8)
{
  unsigned int v8; // ebx
  unsigned __int8 *v10; // [esp-Ch] [ebp-2Ch]
  char v12[8]; // [esp+14h] [ebp-Ch] BYREF
  char v13[4]; // [esp+1Ch] [ebp-4h] BYREF

  *(_DWORD *)v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CSink::CursorUp", (int *)v13);
  if ( AcceptInkInput() )
  {
    if ( (HDC)g_tcid == a4 )
    {
      v8 = a5;
      if ( g_cid == a5 )
      {
        if ( *((_DWORD *)this + 2) )
        {
          v10 = a8;
          *((_DWORD *)this + 2) = 0;
          *(_DWORD *)v13 = (*(int (__stdcall **)(struct IInkCollect *, unsigned int, unsigned int, unsigned __int8 *, int, int))(*(_DWORD *)g_pIInkCollect + 16))(
                             g_pIInkCollect,
                             v8,
                             a7,
                             v10,
                             a2,
                             a1);
          if ( *(int *)v13 < 0
            && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x18u, &stru_1002480, v13[0]);
          }
          a4 = 0;
          GetInkBufferHDC(&a4);
          if ( a4 )
          {
            *(_DWORD *)v13 = (*(int (__stdcall **)(struct IRenderingContext *, unsigned int, HDC))(*(_DWORD *)g_pIRenderingContext
                                                                                                 + 36))(
                               g_pIRenderingContext,
                               v8,
                               a4);
            if ( *(int *)v13 < 0
              && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
              && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x19u, &stru_1002480, v13[0]);
            }
            ReleaseInkBufferHDC(a4);
          }
          *(_DWORD *)v13 = (*(int (__stdcall **)(struct IInkCollect *, unsigned int))(*(_DWORD *)g_pIInkCollect + 20))(
                             g_pIInkCollect,
                             v8);
          if ( *(int *)v13 < 0
            && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
            && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Au, &stru_1002480, v13[0]);
          }
          CInk::SetInkModifiedFlag(*((CInk **)g_pCGameBoard + 2481));
          g_tcid = 0;
          g_cid = -1;
        }
      }
    }
  }
  *(_DWORD *)v13 = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
  return 0;
}
