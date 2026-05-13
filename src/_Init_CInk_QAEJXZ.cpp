#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int Init_CInk(CInk *self)
{
  CInk *v1; // edi
  uint32_t *v2; // eax
  bool v3; // zf
  int v4; // esi
  uint32_t *v6; // [esp+10h] [ebp-68h] BYREF
  int v7; // [esp+14h] [ebp-64h] BYREF
  int v8; // [esp+18h] [ebp-60h] BYREF
  int v9; // [esp+1Ch] [ebp-5Ch]
  int v10; // [esp+20h] [ebp-58h]
  int v11; // [esp+24h] [ebp-54h]
  uint8_t v12[16]; // [esp+28h] [ebp-50h] BYREF
  uint8_t v13[8]; // [esp+38h] [ebp-40h] BYREF
  LPVOID pv; // [esp+40h] [ebp-38h] BYREF
  CInk *v15; // [esp+44h] [ebp-34h]
  uint32_t v16; // [esp+48h] [ebp-30h] BYREF
  LPVOID v17; // [esp+4Ch] [ebp-2Ch] BYREF
  int v18; // [esp+50h] [ebp-28h]
  uint32_t i; // [esp+54h] [ebp-24h]
  int v20; // [esp+58h] [ebp-20h] BYREF
  int v21; // [esp+5Ch] [ebp-1Ch] BYREF
  uint32_t v22; // [esp+60h] [ebp-18h]
  char v23[4]; // [esp+64h] [ebp-14h] BYREF
  int v24; // [esp+74h] [ebp-4h]

  v1 = self;
  v15 = self;
  *(uint32_t *)v23 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CInk::Init", (int*)v23);
  v24 = 0;
  *((uint32_t *)v1 + 4) = 1;
  CleanupTabletContexts();
  *(uint32_t *)v23 = CoCreateInstance(&CLSID_TpcPlatformManager, 0, 1u, &IID_IInkManager, &g_pIInkManager);
  if ( *(int*)v23 < 0 )
  {
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x16u, &stru_1002480, v23[0]);
  }
  else
  {
    *(uint32_t *)v23 = (*(int (__stdcall **)(LPVOID))(*(uint32_t *)g_pIInkManager + 12))(g_pIInkManager);
    if ( *(int*)v23 < 0 )
    {
      if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x15u, &stru_1002480, v23[0]);
    }
    else
    {
      *(uint32_t *)v23 = (*(int (__stdcall **)(LPVOID, struct IInkObject **))(*(uint32_t *)g_pIInkManager + 20))(
                         g_pIInkManager,
                         &g_pIInkObject);
      if ( *(int*)v23 < 0 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x14u, &stru_1002480, v23[0]);
      }
      else
      {
        *(uint32_t *)v23 = (**(int (__stdcall ***)(struct IInkObject *, GUID *, struct IRenderInk **))g_pIInkObject)(
                           g_pIInkObject,
                           &IID_IRenderInk,
                           &g_pIRenderInk);
        if ( *(int*)v23 < 0 )
        {
          if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x13u, &stru_1002480, v23[0]);
        }
        else
        {
          *(uint32_t *)v23 = (**(int (__stdcall ***)(struct IInkObject *, GUID *, struct IInkCollect **))g_pIInkObject)(
                             g_pIInkObject,
                             &IID_IInkCollect,
                             &g_pIInkCollect);
          if ( *(int*)v23 < 0 )
          {
            if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x12u, &stru_1002480, v23[0]);
          }
          else
          {
            *(uint32_t *)v23 = (*(int (__stdcall **)(struct IInkObject *, void*))(*(uint32_t *)g_pIInkObject + 52))(
                               g_pIInkObject,
                               &g_rcInkSpace);
            *(uint32_t *)v23 = (*(int (__stdcall **)(struct IInkObject *, int*, uint32_t, struct IRenderingContext **))(*(uint32_t *)g_pIInkObject + 136))(
                               g_pIInkObject,
                               dword_10029E0,
                               0,
                               &g_pIRenderingContext);
            if ( *(int*)v23 < 0 )
            {
              if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x11u, &stru_1002480, v23[0]);
            }
            else
            {
              *(uint32_t *)v23 = (*(int (__stdcall **)(struct IRenderingContext *, void*, struct HWND__ *))(*(uint32_t *)g_pIRenderingContext + 24))(
                                 g_pIRenderingContext,
                                 &g_rcInkSpace,
                                 &g_rcClient);
              *(uint32_t *)v23 = (**(int (__stdcall ***)(LPVOID, GUID *, struct ITabletManager **))g_pIInkManager)(
                                 g_pIInkManager,
                                 &IID_ITabletManager,
                                 &g_pTabletManager);
              if ( *(int*)v23 < 0 )
              {
                if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                  WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x10u, &stru_1002480, v23[0]);
              }
              else
              {
                v16 = 0;
                *(uint32_t *)v23 = (*(int (__stdcall **)(struct ITabletManager *, uint32_t *))(*(uint32_t *)g_pTabletManager
                                                                                               + 16))(
                                   g_pTabletManager,
                                   &v16);
                if ( *(int*)v23 >= 0 )
                {
                  for ( i = 0; ; ++i )
                  {
                    if ( i >= v16 || *(int*)v23 < 0 )
                      goto LABEL_70;
                    v20 = 0;
                    *(uint32_t *)v23 = (*(int (__stdcall **)(struct ITabletManager *, uint32_t, int*))(*(uint32_t *)g_pTabletManager + 20))(
                                       g_pTabletManager,
                                       i,
                                       &v20);
                    if ( *(int*)v23 >= 0 )
                      break;
                    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0xEu, &stru_1002480, v23[0]);
LABEL_45:
                    ;
                  }
                  v6 = 0;
                  v7 = 0;
                  v8 = 0;
                  v9 = 0;
                  v10 = 0;
                  v11 = 0;
                  v21 = 0;
                  LOBYTE(v24) = 1;
                  v2 = operator new(0xCu);
                  if ( v2 )
                  {
                    *v2 = &CSink::`vftable';
                    v2[1] = 0;
                    v2[2] = 0;
                  }
                  else
                  {
                    v2 = 0;
                  }
                  v6 = v2;
                  v24 = 0;
                  if ( v2 )
                  {
                    (*(void (__stdcall **)(uint32_t *))(*v6 + 4))(v6);
                    *(uint32_t *)v23 = (*(int (__stdcall **)(uint32_t *, GUID *, int*))*v6)(
                                       v6,
                                       &IID_ITabletEventSink,
                                       &v21);
                    if ( *(int*)v23 >= 0 )
                      goto LABEL_23;
                    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0xBu, &stru_1002480, v23[0]);
                    (*(void (__stdcall **)(uint32_t *))(*v6 + 8))(v6);
                  }
                  if ( *(int*)v23 < 0 )
                  {
LABEL_41:
                    (*(void (__stdcall **)(int))(*(uint32_t *)v20 + 8))(v20);
                    goto LABEL_45;
                  }
LABEL_23:
                  v17 = 0;
                  *(uint32_t *)v23 = (*(int (__stdcall **)(int, HWND, uint32_t, uint32_t, uint32_t, int, int*, int*, LPVOID *, int))(*(uint32_t *)v20 + 16))(
                                     v20,
                                     g_hWnd,
                                     0,
                                     0,
                                     0,
                                     1,
                                     &v7,
                                     &v8,
                                     &v17,
                                     v21);
                  if ( *(int*)v23 < 0 )
                  {
                    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0xDu, &stru_1002480, v23[0]);
                  }
                  else
                  {
                    *(uint32_t *)v23 = (*(int (__stdcall **)(int, LPVOID *))(*(uint32_t *)v20 + 12))(v20, &pv);
                    if ( *(int*)v23 >= 0 )
                    {
                      v10 = *(uint32_t *)pv;
                      v3 = *((uint32_t *)pv + 2) == 0;
                      v22 = 0;
                      if ( !v3 )
                      {
                        v18 = 0;
                        do
                        {
                          if ( !memcmp(
                                  (const void*)GUID_BARRELDOWN.Data1,
                                  (const void*)(v18 + *((uint32_t *)pv + 3)),
                                  0x10u) )
                            v11 = 1 << v22;
                          ++v22;
                          v18 += 16;
                        }
                        while ( v22 < *((uint32_t *)pv + 2) );
                        v1 = v15;
                      }
                      CoTaskMemFree(pv);
                    }
                    v9 = *(uint32_t *)v17;
                    *(uint32_t *)v23 = (*(int (__stdcall **)(struct IInkObject *, int, LPVOID))(*(uint32_t *)g_pIInkObject
                                                                                            + 60))(
                                       g_pIInkObject,
                                       v8,
                                       v17);
                    CoTaskMemFree(v17);
                    *(uint32_t *)v23 = (*(int (__stdcall **)(int, uint8_t *))(*(uint32_t *)v7 + 56))(v7, v12);
                    *(uint32_t *)v23 = (*(int (__stdcall **)(struct IInkObject *, int, uint8_t *, void*))(*(uint32_t *)g_pIInkObject + 132))(
                                       g_pIInkObject,
                                       v8,
                                       v12,
                                       &g_rcTabletInInk);
                    *((uint32_t *)v1 + 3) = 0;
                    *((uint32_t *)v1 + 2) = 0;
                    *(uint32_t *)v23 = CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetAtGrow(
                                       &g_arrTCI,
                                       dword_10B068C,
                                       &v6);
                    if ( *(int*)v23 < 0
                      && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
                      && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0xCu, &stru_1002480, v23[0]);
                    }
                  }
                  if ( v21 )
                  {
                    (*(void (__stdcall **)(int))(*(uint32_t *)v21 + 8))(v21);
                    v21 = 0;
                  }
                  goto LABEL_41;
                }
                if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                  WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0xFu, &stru_1002480, v23[0]);
              }
            }
          }
        }
      }
    }
  }
LABEL_70:
  v4 = *(uint32_t *)v23;
  v24 = -1;
  ((Helpers::CLogBlock*)v13)->~CLogBlock();
  return v4;
}

