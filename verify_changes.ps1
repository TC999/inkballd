# 验证修改结果
Write-Host "=== 验证修改结果 ==="

# 检查是否还有重复的结构体定义
$remainingCLogBlock = Get-ChildItem "G:\Game_src\inkball\src" -Filter "*.cpp" | 
    Where-Object { (Get-Content $_.FullName -Raw) -match 'class Helpers\s*\{.*?class CLogBlock' }

if ($remainingCLogBlock) {
    Write-Warning "Still contains CLogBlock definitions:"
    $remainingCLogBlock | ForEach-Object { Write-Host "  - $($_.Name)" }
} else {
    Write-Host "✓ No CLogBlock definitions found"
}

# 检查其他结构体
$otherStructures = @("CMovingObject", "BallPoints", "CBall", "CSurface", "CBitmapRects", "CBallManager")
foreach ($struct in $otherStructures) {
    $remaining = Get-ChildItem "G:\Game_src\inkball\src" -Filter "*.cpp" | 
        Where-Object { (Get-Content $_.FullName -Raw) -match "class $struct\s*\{" }
    
    if ($remaining) {
        Write-Warning "Still contains $struct definitions:"
        $remaining | ForEach-Object { Write-Host "  - $($_.Name)" }
    } else {
        Write-Host "✓ No $struct definitions found"
    }
}

Write-Host "=== 验证完成 ==="