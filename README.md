# CpuSchedulingSimulator
## Overview
CpuSchedulingSimulator is a C++ simulation of a basic operating system environment. The simulation involves CPU and resource management, process scheduling, and deadlock detection. The CPU runs multiple processes using the Round Robin algorithm and a priority queue, simulating typical OS behavior for CPU scheduling and resource allocation.

## Features
- Round Robin Scheduling: The simulation manages processes in a cyclic order, with each process receiving a fixed time slice.
- Resource Management: Each process requires a set of three resources (R1, R2, R3) for execution.
- Priority Queue: Processes are organized based on their duration, with shorter durations receiving higher priority.
- Dynamic Process Generation: After a process completes, the CPU randomly generates a new process with randomized resource requirements.


## Simulation Details

Process Attributes

  Each process has the following properties:
    -  PID: A unique Process ID.
    -  Duration: The CPU time required for execution.
    -  Resource Requirements (R1, R2, R3): The resources needed to run the process.
    -  InUse Flag: Indicates whether the process has previously been executed.

  How It Works
    -  Resource Allocation: Each process requires specific resources to execute. If the resources are not available, the process waits in the queue.
    -  Execution: Processes are executed according to the Round Robin algorithm. A priority queue ensures processes with shorter durations are prioritized.
    -  Resource Release: When a process finishes, its resources are released and added to the available pool.
    -  Process Creation: After a process completes, the CPU generates a new process with randomized attributes.

## Example Output

    Time: 1
    Priority Queue: F(P1:3, P2:2, P3:5)
    Available resources: R(10, 10, 10)
    Recently executed process: P2
    ...
