# File Organization Schemes for Single-Level and Two-Level Directory

This experiment demonstrates two file organization schemes used by operating systems to organize files and avoid file name conflicts.

## Use Case

**College LMS Assignment Submission System**

A college LMS stores assignments submitted by students. A single-level directory stores all files in one common directory, while a two-level directory separates files based on individual students.

## Schemes Implemented

1. Single-Level Directory
2. Two-Level Directory

## Programs

### Single-Level Directory

All files are stored in one common directory. Since there is no user separation, two files cannot have the same name.

**File:** `Single_Level/single_level.c`

### Two-Level Directory

Each student has a separate directory. Therefore, different students can have files with the same name without creating a conflict.

**File:** `Two_Level/two_level.c`

## Concepts Covered

- File organization
- Directory structure
- Single-level directory
- Two-level directory
- File name conflicts
- User-based file separation

