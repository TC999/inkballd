# Script to fix .cpp files for MSVC C++17 compatibility
# Process files from G:\Game_src\inkball\src

$srcDir = "G:\Game_src\inkball\src"
$processedCount = 0
$failedFiles = @()
$successFiles = @()

# Get all .cpp files modified on 2026-05-07 between 01:00:00 and 02:00:00
$files = Get-ChildItem "$srcDir\*.cpp" | Where-Object { 
    $_.LastWriteTime -gt '2026-05-07 01:00:00' -and $_.LastWriteTime -lt '2026-05-07 02:00:00' 
}

Write-Host "Found $($files.Count) files to process"

# Common headers to add
$headerContent = @"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"

"@

# Process each file
foreach ($file in $files) {
    $fileName = $file.Name
    $filePath = $file.FullName
    
    # Read file content
    try {
        $content = Get-Content -Path $filePath -Raw -Encoding UTF8 -ErrorAction Stop
    } catch {
        Write-Host "ERROR reading $fileName : $_" -ForegroundColor Red
        $failedFiles += @{ FileName = $fileName; Error = "Read error: $_" }
        continue
    }
    
    # Skip empty files
    if ([string]::IsNullOrWhiteSpace($content) -or $content.Trim() -eq "None") {
        Write-Host "Skipping empty file: $fileName"
        continue
    }
    
    # Skip files that already have been processed (check for cstdint)
    if ($content -match '#include <cstdint>') {
        Write-Host "Already processed: $fileName"
        $successFiles += $fileName
        $processedCount++
        continue
    }
    
    # Store original for comparison
    $originalContent = $content
    
    # === REPLACEMENTS ===
    
    # 1. Add necessary includes at the beginning
    $content = $headerContent + $content
    
    # 2. Replace type definitions
    $content = $content -replace '\b_BYTE\b', 'uint8_t'
    $content = $content -replace '\b_WORD\b', 'uint16_t'
    $content = $content -replace '\b_DWORD\b', 'uint32_t'
    $content = $content -replace '\b_QWORD\b', 'uint64_t'
    $content = $content -replace '\b__int64\b', 'int64_t'
    $content = $content -replace '\bunsigned __int16\b', 'uint16_t'
    $content = $content -replace '\bunsigned __int64\b', 'uint64_t'
    
    # 3. Replace unsigned int with uint32_t
    $content = $content -replace '\bunsigned int\b', 'uint32_t'
    
    # 4. Remove GCC __attribute__ syntax
    $content = $content -replace '\s*__attribute__\s*\(\s*\([^)]+\)\s*\)', ''
    
    # 5. Fix pointer dereference casts
    $content = $content -replace '\*\(_DWORD \*\)', '*reinterpret_cast<uint32_t*>'
    $content = $content -replace '\*\(_WORD \*\)', '*reinterpret_cast<uint16_t*>'
    $content = $content -replace '\*\(_BYTE \*\)', '*reinterpret_cast<uint8_t*>'
    $content = $content -replace '\*\(_QWORD \*\)', '*reinterpret_cast<uint64_t*>'
    
    # 6. Fix pointer casts for pointer arithmetic
    $content = $content -replace '\(_DWORD \*\)', '(uint32_t *)'
    $content = $content -replace '\(_WORD \*\)', '(uint16_t *)'
    $content = $content -replace '\(_BYTE \*\)', '(uint8_t *)'
    $content = $content -replace '\(_QWORD \*\)', '(uint64_t *)'
    
    # 7. Fix __imp_ prefixed Windows API calls
    $content = $content -replace '\b__imp_([A-Za-z0-9_]+)\b', '$1'
    
    # 8. Fix struct CBall * to CBall*
    $content = $content -replace '\bstruct CBall \*', 'CBall*'
    $content = $content -replace '\bstruct CGameBoard \*', 'CGameBoard*'
    $content = $content -replace '\bstruct CBoardTile \*', 'CBoardTile*'
    $content = $content -replace '\bstruct CGameManager \*', 'CGameManager*'
    $content = $content -replace '\bstruct CDisplay \*', 'CDisplay*'
    $content = $content -replace '\bstruct CSurface \*', 'CSurface*'
    $content = $content -replace '\bstruct CScoreManager \*', 'CScoreManager*'
    $content = $content -replace '\bstruct CTileManager \*', 'CTileManager*'
    $content = $content -replace '\bstruct CTimeManager \*', 'CTimeManager*'
    $content = $content -replace '\bstruct CInk \*', 'CInk*'
    $content = $content -replace '\bstruct CSink \*', 'CSink*'
    $content = $content -replace '\bstruct CGameObject \*', 'CGameObject*'
    $content = $content -replace '\bstruct CMovingObject \*', 'CMovingObject*'
    $content = $content -replace '\bstruct CUIBarObject \*', 'CUIBarObject*'
    $content = $content -replace '\bstruct CBoardTileWall \*', 'CBoardTileWall*'
    $content = $content -replace '\bstruct CBoardTileBreakWall \*', 'CBoardTileBreakWall*'
    $content = $content -replace '\bstruct CBoardTileBumper \*', 'CBoardTileBumper*'
    $content = $content -replace '\bstruct CBoardTileChevron \*', 'CBoardTileChevron*'
    $content = $content -replace '\bstruct CBoardTileDrain \*', 'CBoardTileDrain*'
    $content = $content -replace '\bstruct CBoardTileOWF \*', 'CBoardTileOWF*'
    $content = $content -replace '\bstruct CBoardTileRLColored \*', 'CBoardTileRLColored*'
    $content = $content -replace '\bstruct CBoardTileRLGray \*', 'CBoardTileRLGray*'
    $content = $content -replace '\bstruct CBitmapRects \*', 'CBitmapRects*'
    $content = $content -replace '\bstruct CBallManager \*', 'CBallManager*'
    $content = $content -replace '\bstruct CRegistryManager \*', 'CRegistryManager*'
    $content = $content -replace '\bstruct CTabLicense \*', 'CTabLicense*'
    
    # 9. Fix wchar_t pointer types
    $content = $content -replace '\bPBG\b', 'const wchar_t*'
    $content = $content -replace '\bPAG\b', 'wchar_t*'
    
    # 10. Fix spacing in pointer types
    $content = $content -replace '\bvoid \*', 'void*'
    $content = $content -replace '\bchar \*', 'char*'
    $content = $content -replace '\bint \*', 'int*'
    $content = $content -replace '\blong \*', 'long*'
    $content = $content -replace '\bshort \*', 'short*'
    
    # 11. Fix pointer arithmetic with (char *)this
    $content = $content -replace '\(char \*\)this', 'reinterpret_cast<char*>(this)'
    $content = $content -replace '\(char \*\)a1', 'reinterpret_cast<char*>(a1)'
    $content = $content -replace '\(char \*\)a2', 'reinterpret_cast<char*>(a2)'
    $content = $content -replace '\(char \*\)a3', 'reinterpret_cast<char*>(a3)'
    $content = $content -replace '\(char \*\)a4', 'reinterpret_cast<char*>(a4)'
    
    # Write modified content back
    try {
        Set-Content -Path $filePath -Value $content -Encoding UTF8 -NoNewline -ErrorAction Stop
        Write-Host "Processed: $fileName"
        $successFiles += $fileName
        $processedCount++
    } catch {
        Write-Host "ERROR writing $fileName : $_" -ForegroundColor Red
        $failedFiles += @{ FileName = $fileName; Error = "Write error: $_" }
    }
}

# Summary
Write-Host "`n=== SUMMARY ===" -ForegroundColor Cyan
Write-Host "Total processed: $processedCount"
Write-Host "Successful: $($successFiles.Count)" -ForegroundColor Green
Write-Host "Failed: $($failedFiles.Count)" -ForegroundColor Red

if ($failedFiles.Count -gt 0) {
    Write-Host "`nFailed files:" -ForegroundColor Red
    foreach ($f in $failedFiles) {
        Write-Host "  - $($f.FileName): $($f.Error)"
    }
}

# Save success list to file
$successFiles | Out-File -FilePath "$srcDir\..\processed_files.txt" -Encoding UTF8
Write-Host "`nProcessed file list saved to processed_files.txt"
