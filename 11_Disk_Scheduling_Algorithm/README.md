# CCTV Storage System Using Disk Scheduling Algorithms

## Overview
This project demonstrates the use of disk scheduling algorithms in a CCTV storage system. CCTV cameras continuously store video recordings, and disk scheduling helps decide the order in which disk requests are processed.

The program implements six disk scheduling algorithms and calculates the total disk head movement for each one.

## Use Case
In a CCTV system, video recordings from multiple cameras are stored on a disk. When recordings need to be accessed, disk scheduling algorithms determine the order in which the requests are processed. This helps compare different methods of managing disk access.

## Algorithms Implemented
- **FCFS:** Processes requests in the order they arrive.
- **SSTF:** Processes the request closest to the current head position.
- **SCAN:** Moves the disk head in one direction and then reverses.
- **C-SCAN:** Moves in one direction and returns to the beginning.
- **LOOK:** Reverses direction after reaching the last request in that direction.
- **C-LOOK:** Moves to the last request and jumps to the first request on the other side.

## Technologies Used
- C Programming
- Operating Systems – Disk Scheduling

## How to Run
Compile the program:

```bash
gcc DISKSCHED.C -o disksched
```

Run the program:

```bash
./disksched
```

## Output
The program displays the disk head movement sequence and total head movement for each algorithm.

## Conclusion
This project compares six disk scheduling algorithms using a CCTV storage scenario and demonstrates how they manage disk requests differently.
