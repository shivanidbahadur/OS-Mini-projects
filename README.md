# Operating Systems Mini Projects

This repository contains C programs implemented as part of Operating Systems lab practice. The programs cover process management, CPU scheduling, deadlocks, memory management, disk scheduling, file allocation, page replacement, and synchronization.

## Topics Covered

### Process Management
- Process creation using `fork()`
- Process execution and parent-child processes
- Multithreading using POSIX threads
- Process and thread synchronization

### CPU Scheduling
- First Come First Serve (FCFS)
- Shortest Job First (SJF)
- Priority Scheduling
- Round Robin Scheduling

### Deadlocks
- Deadlock demonstration using threads and mutex locks
- Deadlock avoidance using resource locking
- Safe-state checking using a simplified Banker's algorithm

### Memory Management
- Best Fit memory allocation
- Worst Fit memory allocation

### Disk Scheduling
- First Come First Serve (FCFS)
- Shortest Seek Time First (SSTF)
- SCAN
- Circular SCAN (C-SCAN)
- LOOK
- Circular LOOK (C-LOOK)

### File Allocation
- Sequential File Allocation
- Indexed File Allocation

### Page Replacement
- First In First Out (FIFO)
- Least Recently Used (LRU)
- Least Frequently Used (LFU)

### File Organization
- Single-Level Directory
- Two-Level Directory

### Mutual Exclusion and Synchronization
- Mutex-based mutual exclusion
- Semaphore-based synchronization
- Combined semaphore and mutex-based synchronization

## Technologies Used
- C
- GCC Compiler
- Linux / WSL
- POSIX Threads (`pthread`)
- POSIX Semaphores

## How to Compile and Run

1. Clone the repository:

   ```bash
   git clone https://github.com/shivanidbahadur/OS-Mini-projects.git
   ```

2. Navigate to the project directory:

   ```bash
   cd OS-Mini-projects
   ```

3. Navigate to the folder containing the required C program.

4. Compile the program using GCC:

   ```bash
   gcc filename.c -o output
   ```

5. Run the program:

   ```bash
   ./output
   ```

For programs using POSIX threads or semaphores, compile with the `-pthread` flag:

```bash
gcc filename.c -o output -pthread
```

Replace `filename.c` with the actual C source filename.

## Purpose

These programs demonstrate basic Operating Systems concepts through practical C implementations. They help understand process execution, scheduling, memory allocation, resource management, file organization, and synchronization.

## Repository

GitHub: [OS-Mini-projects](https://github.com/shivanidbahadur/OS-Mini-projects?utm_source=chatgpt.com)
