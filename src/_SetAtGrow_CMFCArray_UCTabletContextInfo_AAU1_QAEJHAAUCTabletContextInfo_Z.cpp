#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

template<class TYPE, class ARG_TYPE>
struct CMFCArray {
    TYPE* m_pData;
    int m_nSize;
    int m_nMaxSize;
    int m_nGrowBy;
    int SetSize(int nNewSize, int nGrowBy);
};

template<class TYPE, class ARG_TYPE>
int CMFCArray<TYPE, ARG_TYPE>::SetSize(int nNewSize, int nGrowBy) {
    return 0;
}

extern void* qmemcpy(void* dst, const void* src, size_t n);

int SetAtGrow_CMFCArray_CTabletContextInfo_CTabletContextInfo___(uint32_t *self, int a2, const void*a3)
{
  int result; // eax

  result = 0;
  if ( a2 < 0 )
    return -2147024809;
  if ( a2 < self[1]
    || (result = ((CMFCArray<CTabletContextInfo,CTabletContextInfo&>*)(void*)self)->SetSize(a2 + 1, -1), result >= 0) )
  {
    qmemcpy((void*)(*self + 24 * a2), a3, 0x18u);
  }
  return result;
}
