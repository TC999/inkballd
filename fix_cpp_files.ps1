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

# Process each file
foreach ($file in $files) {
    $fileName = $file.Name
    $filePath = $file.FullName
    
    Write-Host "Processing: $fileName"
    
    # Read file content
    $content = Get-Content -Path $filePath -Raw -Encoding UTF8
    
    # Skip empty files
    if ([string]::IsNullOrWhiteSpace($content) -or $content.Trim() -eq "None") {
        Write-Host "  Skipping empty file"
        continue
    }
    
    # Store original for comparison
    $originalContent = $content
    
    # === REPLACEMENTS ===
    
    # 1. Add necessary includes at the beginning (if not present)
    $includes = @"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"

"@
    
    # Check if file already has includes
    if (-not ($content -match '#include')) {
        $content = $includes + $content
    }
    
    # 2. Replace type definitions
    $content = $content -replace '\b_BYTE\b', 'uint8_t'
    $content = $content -replace '\b_WORD\b', 'uint16_t'
    $content = $content -replace '\b_DWORD\b', 'uint32_t'
    $content = $content -replace '\b_QWORD\b', 'uint64_t'
    $content = $content -replace '\b__int64\b', 'int64_t'
    $content = $content -replace '\bunsigned __int16\b', 'uint16_t'
    $content = $content -replace '\bunsigned __int64\b', 'uint64_t'
    
    # 3. Replace unsigned int with uint32_t (only when used as type, not in casts with pointer)
    $content = $content -replace '\bunsigned int\b', 'uint32_t'
    
    # 4. Remove GCC __attribute__ syntax
    $content = $content -replace '\s*__attribute__\s*\(\s*\([^)]+\)\s*\)', ''
    
    # 5. Fix pointer casts - replace *\(_DWORD \*\) with *reinterpret_cast<uint32_t*> and similar
    $content = $content -replace '\*\(_DWORD \*\)', '*reinterpret_cast<uint32_t*>'
    $content = $content -replace '\*\(_WORD \*\)', '*reinterpret_cast<uint16_t*>'
    $content = $content -replace '\*\(_BYTE \*\)', '*reinterpret_cast<uint8_t*>'
    $content = $content -replace '\*\(_QWORD \*\)', '*reinterpret_cast<uint64_t*>'
    
    # 6. Fix pointer casts with parentheses like *((_DWORD *)ptr + offset)
    # Replace (_DWORD *) with (uint32_t *) for use in pointer arithmetic
    $content = $content -replace '\(_DWORD \*\)', '(uint32_t *)'
    $content = $content -replace '\(_WORD \*\)', '(uint16_t *)'
    $content = $content -replace '\(_BYTE \*\)', '(uint8_t *)'
    $content = $content -replace '\(_QWORD \*\)', '(uint64_t *)'
    
    # 7. Fix __imp_ prefixed Windows API calls
    $content = $content -replace '\b__imp_([A-Za-z0-9_]+)\b', '$1'
    
    # 8. Add extern "C" before sub_ function definitions if not already present
    # This is tricky - let's check if sub_ functions are defined (not just called)
    $content = $content -replace '^(\s*)(int __cdecl sub_\w+)', '$1extern "C" $2'
    
    # 9. Rename common variables (v1, v2, etc.) to more meaningful names
    # This is complex and might need manual review - skip for now or do simple replacement
    # Note: Variable renaming is risky without context, so we'll skip it for automated processing
    
    # 10. Fix struct references
    $content = $content -replace '\bstruct CBall \*', 'CBall*'
    $content = $content -replace '\bstruct CGameBoard \*', 'CGameBoard*'
    $content = $content -replace '\bstruct CBoardTile \*', 'CBoardTile*'
    
    # 11. Fix __thiscall - keep as is since MSVC supports it
    
    # 12. Fix wchar_t* with PBG/PAG
    $content = $content -replace '\bPBG\b', 'const wchar_t*'
    $content = $content -replace '\bPAG\b', 'wchar_t*'
    
    # 13. Fix void * to void*
    $content = $content -replace '\bvoid \*', 'void*'
    $content = $content -replace '\bchar \*', 'char*'
    $content = $content -replace '\bint \*', 'int*'
    
    # 14. Fix specific patterns for pointer arithmetic
    # (char *)this + offset -> reinterpret_cast<char*>(this) + offset
    $content = $content -replace '\(char \*\)this', 'reinterpret_cast<char*>(this)'
    $content = $content -replace '\(char \*\)a1', 'reinterpret_cast<char*>(a1)'
    $content = $content -replace '\(char \*\)a2', 'reinterpret_cast<char*>(a2)'
    
    # Write modified content back
    Set-Content -Path $filePath -Value $content -Encoding UTF8 -NoNewline
    
    # Compile to verify
    Write-Host "  Compiling..."
    $compileOutput = & cl /c /std:c++17 /EHsc /nologo /W0 /FoNUL "$filePath" 2>&1
    $compileResult = $LASTEXITCODE
    
    if ($compileResult -eq 0) {
        Write-Host "  SUCCESS" -ForegroundColor Green
        $successFiles += $fileName
    } else {
        Write-Host "  FAILED" -ForegroundColor Red
        Write-Host "  Error: $compileOutput"
        $failedFiles += [PSCustomObject]@{
            FileName = $fileName
            Error = $compileOutput -join "`n"
        }
    }
    
    $processedCount++
}

# Summary
Write-Host "`n=== SUMMARY ===" -ForegroundColor Cyan
Write-Host "Total processed: $processedCount"
Write-Host "Successful: $($successFiles.Count)" -ForegroundColor Green
Write-Host "Failed: $($failedFiles.Count)" -ForegroundColor Red

if ($failedFiles.Count -gt 0) {
    Write-Host "`nFailed files:" -ForegroundColor Red
    foreach ($f in $failedFiles) {
        Write-Host "  - $($f.FileName)"
    }
}
