# 直接清理重复结构体定义
$filesToClean = @(
    "G:\Game_src\inkball\src\_0CBallManager_QAE_XZ.cpp",
    "G:\Game_src\inkball\src\_0CBall_QAE_PAUtagRECT_W4BOARD_COLOR_HH_Z.cpp", 
    "G:\Game_src\inkball\src\_0BallPoints_QAE_H_Z.cpp"
)

foreach ($file in $filesToClean) {
    if (Test-Path $file) {
        Write-Host "Processing: $file"
        $content = Get-Content $file -Raw
        
        # 直接删除整个Helpers块
        $content = $content -replace 'class Helpers\s*\{[\s\S]*?class CLogBlock[\s\S]*?\};[\s\S]*?\}', ''
        
        # 删除其他结构体定义，逐个处理
        $content = $content -replace 'class CSurface\s*\{[\s\S]*?\};', ''
        $content = $content -replace 'class CBitmapRects\s*\{[\s\S]*?\};', ''
        $content = $content -replace 'class CBall\s*\{[\s\S]*?\};', ''
        $content = $content -replace 'class CBallManager\s*\{[\s\S]*?\};', ''
        $content = $content -replace 'class CMovingObject\s*\{[\s\S]*?\};', ''
        $content = $content -replace 'class BallPoints\s*\{[\s\S]*?\};', ''
        
        # 清理多余的括号和空行
        $content = $content -replace '\}\}\}\}', '}'
        $content = $content -replace '\n\s*\n\s*;', ';'
        $content = $content -replace '\n{3,}', "\n\n"
        
        # 保存文件
        $content | Set-Content $file -NoNewline
        Write-Host "  -> Cleaned successfully"
    }
}

Write-Host "Direct cleanup completed!"