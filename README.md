# Virtualized Operating System Project

## Overview
This project is designed to implement multiple C scripts within a virtualized operating system environment. The tasks focus on input/output operations, process management, client-server communication, and multi-threading with synchronization.

## Project Tasks

### Task 1: Standard Input/Output Script
1. Create a script using C that:
   - Reads any data from the standard input device.
   - Writes the data to the screen.
   - Handles data of any length.

### Task 2: Date and Time Script
2. Create a script using C that:
   - Prints the day of the week.
   - Creates a forked process to print the current date.

### Task 3: Client-Server Communication
3. Create three C scripts:
   - **Script A (Server)**
     - Prints the messages received from Scripts B & C.
     - Replies to the messages received from Script B or C.
   - **Script B (Client)**
     - Sends the message "This is Client B" to the server.
     - Prints the reply received from Script A.
   - **Script C (Client)**
     - Sends the message "I am Client C" to the server.
     - Prints the reply received from Script A.

### Task 4: Multi-Threading with Synchronization
4. Create a script using C that:
   - Creates two threads (Thread A and Thread B).
   - Ensures the threads alternate using a Mutex lock to achieve synchronized output.
   - The output sequence should follow:
     ```
     1 ➔ 2 ➔ 2 ➔ 4 ➔ 3 ➔ 6 ➔ 4 ➔ 8 ➔ 5 ➔ 10 ➔ 6 ➔ 12 ➔ 7 ➔ 14
     ```
     - Thread A prints numbers from 1 to 7.
     - Thread B prints even numbers from 2 to 14.

---

## Requirements
- Virtualized Operating System environment.
- GCC compiler for C language.
- Mutex library for thread synchronization.
