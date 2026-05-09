# Fix remaining (char*) patterns
$srcDir = "G:\Game_src\inkball\src"

$files = Get-ChildItem "$srcDir\*.cpp"

foreach ($file in $files) {
    $content = Get-Content -Path $file.FullName -Raw -Encoding UTF8
    
    # Check if file has (char*) pattern
    if ($content -match '\(char\*\)') {
        # Replace (char*) patterns with reinterpret_cast
        $content = $content -replace '\(char\*\)this', 'reinterpret_cast<char*>(this)'
        $content = $content -replace '\(char\*\)a1', 'reinterpret_cast<char*>(a1)'
        $content = $content -replace '\(char\*\)a2', 'reinterpret_cast<char*>(a2)'
        $content = $content -replace '\(char\*\)a3', 'reinterpret_cast<char*>(a3)'
        $content = $content -replace '\(char\*\)a4', 'reinterpret_cast<char*>(a4)'
        
        Set-Content -Path $file.FullName -Value $content -Encoding UTF8 -NoNewline
        Write-Host "Fixed: $($file.Name)"
    }
}

Write-Host "Done!"
