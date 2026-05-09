# 直接清理重复结构体定义
$files = @(
    "G:\Game_src\inkball\src\_0CBallManager_QAE_XZ.cpp",
    "G:\Game_src\inkball\src\_0CBall_QAE_PAUtagRECT_W4BOARD_COLOR_HH_Z.cpp", 
    "G:\Game_src\inkball\src\_0BallPoints_QAE_H_Z.cpp"
)

foreach ($file in $files) {
    Write-Host "Processing: $file"
    $content = Get-Content $file -Raw
    
    # 删除Helpers块
    $content = $content -replace 'class Helpers\s*\{.*?class CLogBlock.*?\};.*?\}', ''
    
    # 删除其他结构体
    $content = $content -replace 'class CSurface\s*\{.*?\};', ''
    $content = $content -replace 'class CBitmapRects\s*\{.*?\};', ''
    $content = $content -replace 'class CBall\s*\{.*?\};', ''
    $content = $content -replace 'class CBallManager\s*\{.*?\};', ''
    $content = $content -replace 'class CMovingObject\s*\{.*?\};', ''
    $content = $content -replace 'class BallPoints\s*\{.*?\};', ''
    
    # 清理多余括号
    $content = $content -replace '\}\}\}\}', '}'
    
    # 保存
    $content | Set-Content $file -NoNewline
    Write-Host "  -> Done"
}

Write-Host "Cleanup completed!"