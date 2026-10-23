# Disk Scheduling Algorithm

This experiment demonstrates different disk scheduling algorithms used by an operating system to decide the order in which disk I/O requests are serviced.

## Use Case

**CCTV Storage System**

A CCTV system continuously generates storage requests. Disk scheduling algorithms determine the order in which these requests are handled to reduce disk head movement and improve performance.

## Algorithms Implemented

1. FCFS (First Come First Serve)
2. SSTF (Shortest Seek Time First)
3. SCAN
4. C-SCAN (Circular SCAN)
5. LOOK

## Programs

### FCFS
Services disk requests in the same order in which they arrive.

**File:** `FCFS/fcfs.c`

### SSTF
Services the request that is closest to the current disk head position.

**File:** `SSTF/sstf.c`

### SCAN
Moves the disk head in one direction while servicing requests and then reverses direction.

**File:** `SCAN/scan.c`

### C-SCAN
Moves the disk head in one direction, reaches the end, and returns to the beginning before continuing to service requests.

**File:** `C_SCAN/c_scan.c`

### LOOK
Similar to SCAN, but the disk head reverses direction at the last pending request instead of going to the physical end of the disk.

**File:** `LOOK/look.c`

## Concepts Covered

- Disk scheduling
- Disk head movement
- Seek time
- FCFS scheduling
- SSTF scheduling
- SCAN scheduling
- C-SCAN scheduling
- LOOK scheduling
