# Vehicle Speed Monitor (CAN Simulation)!

## Overview

This project is a simulation of a real-time embedded automotive system, written in C, that demonstrates how a vehicle's speed sensor interacts with an Electronic Control Unit (ECU) over a CAN (Controller Area Network) bus. The simulation mimics periodic sensor readings and CAN message transmissions, using RTOS-style scheduling concepts. All activity is output to the console, with color-coded messages for clarity and engagement.

---

## What Does This Project Do?

- **Simulates a Vehicle Speed Sensor:**  
  Generates random speed values (0–120 km/h) at regular intervals, as if reading from a real sensor.

- **Implements RTOS-Style Task Scheduling:**  
  Uses timer-based logic to mimic periodic tasks, similar to what is found in real embedded systems.

- **Simulates CAN Protocol Communication:**  
  Formats and "sends" CAN messages (printed to the console) at fixed intervals, demonstrating understanding of automotive communication standards.

- **Detects Over-Speeding:**  
  If the simulated speed exceeds 100 km/h, the system prints a clear warning message.

- **Colorful, Readable Output:**  
  Uses ANSI color codes to make different types of messages stand out for easier review and demo.

- **Logs Output to File:**  
  (Optional) Can be extended to save all output to a file for analysis or reporting.

---

__________________________________________________________________________________________________

- **Demonstrates Embedded C Skills:**  
  Shows ability to structure code for real-time, event-driven systems.

- **Automotive Protocol Knowledge:**  
  Simulates CAN messaging, a core skill for automotive software roles.

- **RTOS Concepts:**  
  Implements periodic scheduling without relying on OS-specific features.

- **Professional Documentation:**  
  Includes requirements, architecture diagrams, and clear explanations.

- **Easy to Run and Extend:**  
  No hardware required—runs on any PC, making it perfect for interviews or take-home assignments.

---

## Tech Stack

- **Language:** C (C99)
- **Platform:** Windows (uses `Sleep()` from `<windows.h>`)
- **IDE:** Visual Studio Code
- **Version Control:** Git
- **Documentation:** Markdown, Excel, PNG diagrams
- **Simulation Only:** No hardware or external dependencies required

---

## Project Structure

- `src/main.c` – Core simulation logic
- `include/can_comm.h` – (Optional) CAN communication header for modularity
- `docs/requirements.xlsx` – Project requirements and traceability
- `docs/architecture.png` – High-level system architecture diagram

---

## How It Works

1. **Initialization:**  
   Seeds the random number generator and sets up timing variables.

2. **Main Loop (10 seconds):**  
   - Every 500ms: Reads a new simulated speed and prints it.
   - Every 1000ms: Sends a formatted CAN message with the current speed.
   - If speed > 100 km/h: Prints a red warning message.

3. **Output:**  
   - Console output is color-coded for readability.
   - (Optional) All output can be logged to a file for later review.

---

## Sample Output

```
[0.50s] Speed Sensor: 99 km/h
[1.00s] Speed Sensor: 102 km/h
Warning: Over Speeding!
Sending CAN Msg | ID: 0x120 | Payload: Speed = 102 km/h
```

---



| Requirement | Covered in Project |
|----------------|--------------------|
| C/C++ | ✅ |
| RTOS Concepts | ✅ |
| CAN Protocol | ✅ (Simulated) |
| Git & Docs | ✅ |
| DOORS/ASPICE | ✅ (via docs folder) |

---

## How to Run

```bash
gcc src/main.c -o monitor
./monitor      # On Windows, use: monitor.exe
```

-----------------------------------------------------------------------------------------------------------------------------

## Extending the Project

- Add more sensors (e.g., RPM, temperature)
- Log output to CSV for data analysis
- Simulate CAN errors or message loss
- Add user input for dynamic simulation control

---

## Contact
anushreenair15@gmail.com
