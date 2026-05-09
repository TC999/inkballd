# PowerShell script to batch modify .cpp files in src directory
# Add #include "global_types.h" and remove local struct definitions

$srcDir = "src"
$includeLine = '#include "global_types.h"'
$structPattern = '^struct\s+\w+'

Get-ChildItem -Path "$srcDir/*.cpp" | ForEach-Object {
    $filePath = $_.FullName
    Write-Host "Processing: $filePath"
    
    # Read the file content
    $content = Get-Content -Path $filePath -Raw
    
    # Add the include line at the beginning if not already present
    if ($content -notlike "*#include `"global_types.h`"") {
        $content = $includeLine + "`n" + $content
        Write-Host "  Added include line"
    }
    
    # Remove local struct definitions (lines starting with "struct" at the beginning of lines)
    $lines = $content -split "`n"
    $filteredLines = @()
    $inStruct = $false
    $structIndent = 0
    
    foreach ($line in $lines) {
        $trimmedLine = $line.TrimStart()
        
        # Check if this line starts a struct definition
        if ($trimmedLine -match '^struct\s+\w+') {
            $inStruct = $true
            $structIndent = [Math]::Max(0, ($line.Length - $line.TrimStart().Length))
            Write-Host "  Removed struct definition: $trimmedLine"
            continue
        }
        
        # Check if we're still in a struct
        if ($inStruct) {
            # Check if this line is at or above the struct indentation level
            $currentIndent = [Math]::Max(0, ($line.Length - $line.TrimStart().Length))
            if ($currentIndent -le $structIndent -and $trimmedLine -ne '') {
                # We've reached the end of the struct
                $inStruct = $false
                $filteredLines += $line
            }
            continue
        }
        
        $filteredLines += $line
    }
    
    # Join the filtered lines back
    $newContent = $filteredLines -join "`n"
    
    # Write the modified content back to the file
    Set-Content -Path $filePath -Value $newContent -NoNewline
    
    Write-Host "  Completed: $filePath"
}

Write-Host "All files processed."