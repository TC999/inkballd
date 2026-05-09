# 批量删除重复的结构体定义
$filesToProcess = Get-ChildItem "G:\Game_src\inkball\src" -Filter "*.cpp" | 
    Where-Object { 
        $content = Get-Content $_.FullName -Raw
        ($content -match 'class Helpers\s*\{.*?class CLogBlock') -or
        ($content -match 'class CMovingObject\s*\{') -or
        ($content -match 'class BallPoints\s*\{') -or
        ($content -match 'class CBall\s*:\s*public CMovingObject') -or
        ($content -match 'class CSurface\s*\{') -or
        ($content -match 'class CBitmapRects\s*\{') -or
        ($content -match 'class CBallManager\s*\{')
    }

Write-Host "Found $($filesToProcess.Count) files to process..."

foreach ($file in $filesToProcess) {
    Write-Host "Processing: $($file.Name)"
    
    $content = Get-Content $file.FullName -Raw
    
    # 删除重复的CLogBlock定义
    $pattern = 'class Helpers\s*\{.*?class CLogBlock\s*\{.*?~CLogBlock\(\);.*?\};.*?\}'
    $content = $content -replace $pattern, ''
    
    # 删除重复的其他结构体定义
    $content = $content -replace 'class CMovingObject\s*\{.*?\}', ''
    $content = $content -replace 'class BallPoints\s*\{.*?\}', ''
    $content = $content -replace 'class CBall\s*:\s*public CMovingObject\s*\{.*?\}', ''
    $content = $content -replace 'class CSurface\s*\{.*?\}', ''
    $content = $content -replace 'class CBitmapRects\s*\{.*?\}', ''
    $content = $content -replace 'class CBallManager\s*\{.*?\}', ''
    
    # 保存修改后的文件
    $content | Set-Content $file.FullName -NoNewline
}

Write-Host "Batch processing completed!"