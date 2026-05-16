#!/usr/bin/env python3
"""Fix CBall method signatures to match global_types.h declarations, and add missing extern declarations."""

import re
import os

SRC = r"G:\Game_src\inkball\src"

# Fixes for individual files
fixes = {
    "CBall_AddRef.cpp": [
        # line 2: unsigned int CBall::AddRef(CBall* self) -> int CBall::AddRef(CBall* self)
        (r'^unsigned int CBall::AddRef\(CBall\* self\)', r'int CBall::AddRef(CBall* self)'),
    ],
    "CBall_BallsIntersect.cpp": [
        # BOOL CBall::BallsIntersect(CBall* self, const struct CBall* a2) -> int CBall::BallsIntersect(CBall* self, CBall* a2)
        (r'^BOOL CBall::BallsIntersect\(CBall\* self, const struct CBall\* a2\)', 
         r'int CBall::BallsIntersect(CBall* self, CBall* a2)'),
    ],
    "CBall_Collide.cpp": [
        # int CBall::Collide(CBall* self, int (__stdcall *const a2)(const struct tagRECT *))
        # -> int CBall::Collide(CBall* self, void* a2)
        (r'^int CBall::Collide\(CBall\* self, int \(__stdcall \*const a2\)\(const struct tagRECT \*\)\)',
         r'int CBall::Collide(CBall* self, void* a2)'),
        # Also need to fix internal type casts that use BallPoint
        (r'#include "math_utils\.h"\n', ''),
    ],
    "CBall_GetNextPoint.cpp": [
        # BallPoint *CBall::GetNextPoint(CBall* self) -> void* CBall::GetNextPoint(CBall* self)
        (r'^struct BallPoint \*CBall::GetNextPoint\(CBall\* self\)', 
         r'void* CBall::GetNextPoint(CBall* self)'),
        # Also fix return statements that cast to BallPoint*
        # Fix internal references to BallPoint* return values
    ],
    "CBall_GetPoint.cpp": [
        # BallPoint *CBall::GetPoint(CBall* self, int a2) -> int CBall::GetPoint(CBall* self, int index)
        (r'^struct BallPoint \*CBall::GetPoint\(CBall\* self, int a2\)', 
         r'int CBall::GetPoint(CBall* self, int index)'),
    ],
    "CBall_MovingTowards.cpp": [
        # BOOL CBall::MovingTowards(CBall* self, struct CBall* a2) -> int CBall::MovingTowards(CBall* self, void* a2)
        (r'^BOOL CBall::MovingTowards\(CBall\* self, struct CBall\* a2\)', 
         r'int CBall::MovingTowards(CBall* self, void* a2)'),
    ],
    "CBall_VerifyCollision.cpp": [
        # int CBall::VerifyCollision(CBall* self, struct tagRECT* a2, struct tagPOINT* a3)
        # -> int CBall::VerifyCollision(CBall* self, void* rect, void* point)
        (r'^int CBall::VerifyCollision\(CBall\* self, struct tagRECT\* a2, struct tagPOINT\* a3\)',
         r'int CBall::VerifyCollision(CBall* self, void* rect, void* point)'),
    ],
    "CBall_SetTallness.cpp": [
        # void CBall::SetTallness(CBall* self, char *a2) -> void CBall::SetTallness(CBall* self, int tallness)
        (r'^void CBall::SetTallness\(CBall\* self, char \*a2\)', 
         r'void CBall::SetTallness(CBall* self, int tallness)'),
    ],
    "CBall__scalar_deleting_destructor_.cpp": [
        # void CBall::scalar_deleting_destructor(CBall* self, char flags) -> (int flags)
        (r'^void CBall::scalar_deleting_destructor\(CBall\* self, char flags\)',
         r'void CBall::scalar_deleting_destructor(CBall* self, int flags)'),
        # CBall::~CBall(self) is wrong - should return void
    ],
}

for fname, patterns in fixes.items():
    fpath = os.path.join(SRC, fname)
    if not os.path.exists(fpath):
        continue
    with open(fpath, 'r', encoding='utf-8', errors='replace') as f:
        content = f.read()
    
    original = content
    for pattern, replacement in patterns:
        content = re.sub(pattern, replacement, content)
    
    if content != original:
        with open(fpath, 'w', encoding='utf-8') as f:
            f.write(content)
        print(f"  FIXED: {fname}")
    else:
        print(f"  SKIP: {fname}")

print("\nDone with CBall signature fixes.")
