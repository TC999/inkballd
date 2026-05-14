@echo off
chcp 65001 >nul
cd /d "%~dp0"

echo ========================================
echo   清理 IDA 反编译漏网之鱼脚本
echo ========================================
echo 正在扫描当前目录...
echo.

set "count=0"

:: 1. operator new 的包装函数（内存分配，无逻辑）
call :DeleteFile "_GBallPoints_QAEPAXI_Z.cpp"
call :DeleteFile "_GCBallManager_QAEPAXI_Z.cpp"
call :DeleteFile "_GCBall_AAEPAXI_Z.cpp"
call :DeleteFile "_GCDisplay_QAEPAXI_Z.cpp"
call :DeleteFile "_GCGameBoard_QAEPAXI_Z.cpp"
call :DeleteFile "_GCGameManager_QAEPAXI_Z.cpp"
call :DeleteFile "_GCInk_QAEPAXI_Z.cpp"
call :DeleteFile "_GCScoreManager_QAEPAXI_Z.cpp"
call :DeleteFile "_GCSurface_QAEPAXI_Z.cpp"

:: 2. 许可证与遥测检查
call :DeleteFile "_CanRunInkball_CTabLicense_SGHXZ.cpp"
call :DeleteFile "_CanRunInkball_YGHPAH_Z.cpp"
call :DeleteFile "_GetBOOLPermission_CTabLicense_SGHPBGH_Z.cpp"
call :DeleteFile "_TabQueryPolicyValue_TabUtils_YGJPBGHPAH1_Z.cpp"
call :DeleteFile "_GenerateLastErrorHR_TabUtils_YGJJ_Z.cpp"
call :DeleteFile "_WinSqmDWORDEvent_YGXPBU_EVENT_DESCRIPTOR_PAU_GUID_KK_Z.cpp"

:: 3. COM 组件事件接收器（纯模板代码）
call :DeleteFile "_AddRef_CSink_UAGKXZ.cpp"
call :DeleteFile "_Release_CSink_UAGKXZ.cpp"
call :DeleteFile "_QueryInterface_CSink_UAGJABU_GUID_PAPAX_Z.cpp"
call :DeleteFile "_CursorDown_CSink_UAGJKKKKPAE_Z.cpp"
call :DeleteFile "_CursorMove_CSink_UAGJKKPAUHWND_JJ_Z.cpp"
call :DeleteFile "_CursorUp_CSink_UAGJKKKKPAE_Z.cpp"
call :DeleteFile "_Packets_CSink_UAGJKKKPAEPAKK_Z.cpp"
call :DeleteFile "_SystemEvent_CSink_UAGJKKGUtagSYSTEM_EVENT_DATA_Z.cpp"

:: 4. Tablet PC 上下文与旧版兼容胶水
call :DeleteFile "_EnableClassicWispWithPtr_YGHPAPAUIUnknown_Z.cpp"
call :DeleteFile "_CleanupTabletContexts_YGXXZ.cpp"
call :DeleteFile "_GetTabletContextInfo_YGPAUCTabletContextInfo_K_Z.cpp"

:: 5. 安全字符串与 CRT 杂项
call :DeleteFile "StringExHandleOtherFlagsW.cpp"
call :DeleteFile "_StringCchPrintfExW_YAJPAGIPAPAGPAIKPBGZZ.cpp"
call :DeleteFile "_RtlpImageNtHeader_4.cpp"

echo.
echo ========================================
echo   清理完成！共删除了 %count% 个文件。
echo ========================================
pause
exit /b

:DeleteFile
if exist "%~1" (
    del "%~1"
    echo [已删除] %~1
    set /a count+=1
) else (
    echo [已跳过] %~1
)
exit /b