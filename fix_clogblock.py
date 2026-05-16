#!/usr/bin/env python3
"""Fix CLogBlock destructor calls across all .cpp files.
   Pattern: Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)VAR);
   Fix:     ((Helpers::CLogBlock *)VAR)->~CLogBlock();
"""

import re
import os
import glob

SRC = r"G:\Game_src\inkball\src"

files = glob.glob(os.path.join(SRC, "*.cpp"))
fixed_count = 0

for fpath in files:
    with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()
    
    original = content
    
    # Fix destructor calls: Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)VAR)
    # Pattern: Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)IDENTIFIER)
    content = re.sub(
        r'Helpers::CLogBlock::~CLogBlock\(\(Helpers::CLogBlock\s*\*\)\s*(\w+)\)',
        r'((Helpers::CLogBlock *)\1)->~CLogBlock()',
        content
    )
    # Also handle multi-line/null cases
    content = re.sub(
        r'Helpers::CLogBlock::~CLogBlock\(\(Helpers::CLogBlock\s*\*\)\s*([\w\[\]]+)\)',
        r'((Helpers::CLogBlock *)\1)->~CLogBlock()',
        content
    )
    
    if content != original:
        with open(fpath, 'w', encoding='utf-8') as f:
            f.write(content)
        fixed_count += 1
        print(f"  FIXED: {os.path.basename(fpath)}")

print(f"\nFixed {fixed_count} files.")
