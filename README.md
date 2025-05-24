# OS Algorithms in Unix Environment

This repository contains C++ implementations of core Operating System algorithms studied in Bachelors of Technology in Computer Science Engineering course and used in Unix-based systems. 

## Included Algorithms
- **Page Replacement Algorithms**: FIFO, LRU, Optimal
- **CPU Scheduling Algorithms**: FCFS, SJF, Round Robin, Priority Scheduling
- **Deadlock Avoidance**: Banker's Algorithm
- **Memory Management**: First Fit, Best Fit, Worst Fit

Each program is implemented with a focus on clarity and correctness, and is designed to run in a Linux/Unix environment.

## How to Run
Compile using `g++`:
```bash
g++ page_replacement.cpp -o page_replacement
./page_replacement
