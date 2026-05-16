# Batch fix for CBall decompiled source files
# Fixes: 1) __thiscall with explicit this param  2) Backtick characters

$srcDir = "G:\Game_src\inkball\src"

# Get all CBall_*.cpp files
$files = Get-ChildItem -LiteralPath $srcDir -Filter "CBall_*.cpp"

foreach ($file in $files) {
    $content = Get-Content -LiteralPath $file.FullName -Raw
    $name = $file.Name
    Write-Host "Processing: $name"
    
    # === Fix 1: Remove __thiscall from line 2 function signatures ===
    $content = $content -replace '(\w+ )?__thiscall (\w+)::(\w+)\((\w+) \*this\b', '$2::$3($4* self'
    $content = $content -replace '(\w+ \*)?__thiscall (\w+)::(\w+)\((\w+) \*this\b', '$2::$3($4* self'
    
    # Also handle pattern without leading type
    $content = $content -replace '__thiscall '
    
    # === Fix 2: CBall *this -> CBall* self (in function signatures for static methods) ===
    if ($name -match 'CBall_(\w+)\.cpp$' -and $name -ne 'CBall_~CBall.cpp' -and $name -ne 'CBall_CBall.cpp') {
        # For static member functions: change this->self in param and body
        # Replace (CBall *this with (CBall* self
        $content = $content -replace '\(CBall \*this\b', '(CBall* self'
        
        # Replace body references to 'this' pointer (careful with word boundaries)
        $content = $content -replace '\(\*\(\(_DWORD \*\)this ', '(*((_DWORD *)self '
        $content = $content -replace '\(\*\(\(_DWORD \*\)this\+', '(*((_DWORD *)self +'
        $content = $content -replace '\(_DWORD \)this', '(_DWORD)self'
        $content = $content -replace '\*\(_DWORD \*\)this', '*(_DWORD *)self'
        $content = $content -replace '&this;', '&self;'
        $content = $content -replace '\bthis\)', 'self)'
        $content = $content -replace '\bthis,', 'self,'
        $content = $content -replace '\bthis;', 'self;'
        $content = $content -replace '\bthis ', 'self '
        $content = $content -replace '\(this\b', '(self'
        $content = $content -replace '&this\b', '&self'
        $content = $content -replace '\*this\b', '*self'
    }
    
    # === Fix 3: Backtick characters ===
    # Replace backtick in identifiers (0x60)
    if ($name -eq 'CBall_CBall.cpp') {
        $content = $content -replace '\*CBall \*this\b', 'CBall* self'
        $content = $content -replace '&CBall::`vftable'';', '&CBall_vftable;'
        # Replace this references in body
        # In CBall_CBall.cpp, the function is a constructor. Let's keep it but fix the signature
    }
    
    $content = $content -replace 'CBall::`scalar deleting destructor''', 'CBall_scalar_deleting_destructor'
    $content = $content -replace 'BallPoints::`scalar deleting destructor''', 'BallPoints_scalar_deleting_destructor'
    $content = $content -replace '`scalar deleting destructor''', 'scalar_deleting_destructor'
    $content = $content -replace '&CBall::`vftable'';', '&CBall_vftable;'
    $content = $content -replace '`vftable''', 'vftable'
    
    Set-Content -LiteralPath $file.FullName -Value $content -NoNewline
}

Write-Host "Done! Processed $($files.Count) files."
