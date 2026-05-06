int __stdcall CSink::Packets(
        CSink *this,
        HDC a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 *a5,
        unsigned int *a6,
        unsigned int a7)
{
  unsigned int v7; // esi
  int v8; // esi
  _BYTE v10[8]; // [esp+4h] [ebp-Ch] BYREF
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CSink::Packets", &v11);
  if ( !AcceptInkInput() )
    goto LABEL_9;
  if ( (HDC)g_tcid != a2 )
    goto LABEL_9;
  v7 = a7;
  if ( g_cid != a7 || !*((_DWORD *)this + 2) )
    goto LABEL_9;
  CInk::SetInkModifiedFlag(*((CInk **)g_pCGameBoard + 2481));
  v11 = (*(int (__stdcall **)(struct IInkCollect *, unsigned int, unsigned int, unsigned __int8 *))(*(_DWORD *)g_pIInkCollect
                                                                                                  + 16))(
          g_pIInkCollect,
          v7,
          a4,
          a5);
  if ( v11 >= 0 )
  {
    GetInkBufferHDC(&a2);
    v11 = (*(int (__stdcall **)(struct IRenderingContext *, unsigned int, HDC))(*(_DWORD *)g_pIRenderingContext + 36))(
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
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return v8;
}
