#!/usr/bin/env python3
"""Fix CBall decompiled source files - remove __thiscall, fix explicit this param, fix backticks"""

import re
import os

SRC = r"G:\Game_src\inkball\src"

# Files to process
files = sorted([f for f in os.listdir(SRC) if f.startswith("CBall_") and f.endswith(".cpp")])

print(f"Found {len(files)} files to process")

for fname in files:
    fpath = os.path.join(SRC, fname)
    with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()
    
    original = content
    
    # === STEP 1: Replace backtick characters (0x60) ===
    # CBall::`scalar deleting destructor' -> CBall_scalar_deleting_destructor
    content = content.replace("CBall::`scalar deleting destructor'", "CBall_scalar_deleting_destructor")
    content = content.replace("BallPoints::`scalar deleting destructor'", "BallPoints_scalar_deleting_destructor") 
    content = content.replace("`scalar deleting destructor'", "scalar_deleting_destructor")
    content = content.replace("&CBall::`vftable'", "&CBall_vftable")
    content = content.replace("CBall::`vftable'", "CBall_vftable")
    content = content.replace("`vftable'", "vftable")
    
    # === STEP 2: Fix function signatures ===
    lines = content.split('\n')
    
    # Process line 2 (function signature) for __thiscall and explicit this param
    if len(lines) >= 3:
        sig_line = lines[1]  # line index 1 = line 2
        
        # Remove __thiscall keyword
        sig_line = re.sub(r'__thiscall\s+', '', sig_line)
        
        # Detect pattern: ClassName::Method(ClassName *this, ...)
        if 'CBall_~CBall.cpp' == fname:
            # Destructor - remove explicit this param
            sig_line = re.sub(r'void\s+CBall::\s*~CBall\s*\(\s*CBall\s*\*\s*this\s*\)', 'void CBall::~CBall()', sig_line)
        elif 'CBall_CBall.cpp' == fname:
            # Constructor - remove explicit this param
            sig_line = re.sub(
                r'CBall\s*\*\s*CBall::\s*CBall\s*\(\s*CBall\s*\*\s*this\s*,',
                'CBall* CBall::CBall(',
                sig_line
            )
        elif 'CBall__scalar_deleting_destructor_.cpp' == fname:
            # Scalar deleting destructor
            sig_line = re.sub(
                r'CBall\s*\*\s*CBall::\s*scalar_deleting_destructor\s*\(\s*CBall\s*\*\s*this\s*,\s*char\s+a2\s*\)',
                'CBall* CBall_scalar_deleting_destructor(CBall* self, char flags)',
                sig_line
            )
        else:
            # Static member functions: keep CBall:: prefix, rename this->self
            sig_line = re.sub(
                r'(\(?\s*)CBall\s*\*\s*this\b',
                r'\1CBall* self',
                sig_line
            )
            # Also handle case where only CBall *this is the param (no return type prefix)
            sig_line = re.sub(r'\bthis\s*\)', 'self)', sig_line)
            sig_line = re.sub(r'\bthis\s*,', 'self,', sig_line)
        
        lines[1] = sig_line
    
    content = '\n'.join(lines)
    
    # === STEP 3: Rename 'this' -> 'self' in function bodies ===
    # For static member functions, rename all this references to self
    # But not for destructor/constructor (they use implicit this)
    if fname not in ('CBall_~CBall.cpp', 'CBall_CBall.cpp'):
        # Use word boundary regex to replace 'this' as a standalone identifier
        # Be careful not to match 'this' inside other identifiers
        
        def replace_this_in_body(text):
            """Replace standalone 'this' references with 'self'"""
            # Patterns to match, most specific first:
            # (*((_DWORD *)this +  ->  (DWORD*) is inside cast
            text = re.sub(r'\(\*\(\(_DWORD\s*\*\)\s*this\b', '(*((_DWORD *)self', text)
            text = re.sub(r'\(\*\(\(_BYTE\s*\*\)\s*this\b', '(*((_BYTE *)self', text)
            text = re.sub(r'\(\*\(\(_WORD\s*\*\)\s*this\b', '(*((_WORD *)self', text)
            text = re.sub(r'\(\*\(\(int\s*\*\)\s*this\b', '(*((int *)self', text)
            text = re.sub(r'\(\*\(\(void\s*\*\*\)\s*this\b', '(*((void **)self', text)
            text = re.sub(r'\*\(_DWORD\s*\*\)\s*this\b', '*(_DWORD *)self', text)
            text = re.sub(r'\(_DWORD\s*\)\s*this\b', '(_DWORD)self', text)
            text = re.sub(r'\b\(char\s*\*\)\s*this\b', '(char *)self', text)
            
            # Pointer dereference *this
            text = re.sub(r'\*\s*this\b', '*self', text)
            # Address-of &this
            text = re.sub(r'&\s*this\b', '&self', text)
            # Function call with this as argument: func(this, ...)
            text = re.sub(r'\bthis\s*\)', 'self)', text)
            text = re.sub(r'\bthis\s*,', 'self,', text)
            text = re.sub(r'\bthis\s*;', 'self;', text)
            text = re.sub(r'\(\s*this\b', '(self', text)
            text = re.sub(r'\bthis\s*!', 'self!', text)
            text = re.sub(r'\bthis\s*\+', 'self +', text)
            text = re.sub(r'\bthis\s*-', 'self -', text)
            text = re.sub(r'\bthis\s*=', 'self =', text)
            text = re.sub(r'\bthis\s*\n', 'self\n', text)
            text = re.sub(r'\bthis\s*\\n', r'self\n', text)
            # At end of string/line
            text = re.sub(r'\bthis\s*$', 'self', text)
            return text
        
        # Apply to the entire content (after signature is already fixed)
        content = replace_this_in_body(content)
    
    # === Write back ===
    if content != original:
        with open(fpath, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"  FIXED: {fname}")
    else:
        print(f"  SKIP: {fname} (no changes)")

print("\nAll files processed.")
