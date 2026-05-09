# 清理指定的文件
$files = @(
    "G:\Game_src\inkball\src\_0CBallManager_QAE_XZ.cpp",
    "G:\Game_src\inkball\src\_0CBall_QAE_PAUtagRECT_W4BOARD_COLOR_HH_Z.cpp", 
    "G:\Game_src\inkball\src\_0BallPoints_QAE_H_Z.cpp"
)

foreach ($file in $files) {
    Write-Host "Processing: $file"
    $content = Get-Content $file -Raw
    
    # 删除Helpers块
    $content = $content -replace 'class Helpers\s*\{[\s\S]*?class CLogBlock[\s\S]*?\};[\s\S]*?\}', ''
    
    # 删除其他结构体
    $content = $content -replace 'class CSurface\s*\{[\s\S]*?\};', ''
    $content = $content -replace 'class CBitmapRects\s*\{[\s\S]*?\};', ''
    $content = $content -replace 'class CBall\s*\{[\s\S]*?\};', ''
    $content = $content -replace 'class CBallManager\s*\{[\s\S]*?\};', ''
    $content = $content -replace 'class CMovingObject\s*\{[\s\S]*?\};', ''
    $content = $content -replace 'class BallPoints\s*\{[\s\S]*?\};', ''
    
    # 清理多余括号
    $content = $content -replace '\}\}\}\}', '}'
    
    # 保存
    $content | Set-Content $file -NoNewline
    Write-Host "  -> Done"
}