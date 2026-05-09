# 精确删除重复的结构体定义
$filesToProcess = Get-ChildItem "G:\Game_src\inkball\src" -Filter "*.cpp"

Write-Host "Processing $($filesToProcess.Count) files..."

foreach ($file in $filesToProcess) {
    $content = Get-Content $file.FullName -Raw
    $modified = $false
    
    # 检查并删除CLogBlock定义
    if ($content -match 'class Helpers\s*\{.*?class CLogBlock.*?\};.*?\}') {
        Write-Host "Removing CLogBlock from: $($file.Name)"
        $content = $content -replace 'class Helpers\s*\{.*?class CLogBlock.*?\};.*?\}', ''
        $modified = $true
    }
    
    # 检查并删除CMovingObject定义
    if ($content -match 'class CMovingObject\s*\{.*?\};') {
        Write-Host "Removing CMovingObject from: $($file.Name)"
        $content = $content -replace 'class CMovingObject\s*\{.*?\};', ''
        $modified = $true
    }
    
    # 检查并删除BallPoints定义
    if ($content -match 'class BallPoints\s*\{.*?\};') {
        Write-Host "Removing BallPoints from: $($file.Name)"
        $content = $content -replace 'class BallPoints\s*\{.*?\};', ''
        $modified = $true
    }
    
    # 检查并删除CBall定义
    if ($content -match 'class CBall.*?\{.*?\};') {
        Write-Host "Removing CBall from: $($file.Name)"
        $content = $content -replace 'class CBall.*?\{.*?\};', ''
        $modified = $true
    }
    
    # 检查并删除CSurface定义
    if ($content -match 'class CSurface\s*\{.*?\};') {
        Write-Host "Removing CSurface from: $($file.Name)"
        $content = $content -replace 'class CSurface\s*\{.*?\};', ''
        $modified = $true
    }
    
    # 检查并删除CBitmapRects定义
    if ($content -match 'class CBitmapRects\s*\{.*?\};') {
        Write-Host "Removing CBitmapRects from: $($file.Name)"
        $content = $content -replace 'class CBitmapRects\s*\{.*?\};', ''
        $modified = $true
    }
    
    # 检查并删除CBallManager定义
    if ($content -match 'class CBallManager\s*\{.*?\};') {
        Write-Host "Removing CBallManager from: $($file.Name)"
        $content = $content -replace 'class CBallManager\s*\{.*?\};', ''
        $modified = $true
    }
    
    # 如果有修改，保存文件
    if ($modified) {
        $content | Set-Content $file.FullName -NoNewline
        Write-Host "  -> Modified"
    }
}

Write-Host "Precise cleanup completed!"