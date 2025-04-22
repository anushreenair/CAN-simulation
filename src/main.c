#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // for Sleep()

#define TASK_INTERVAL_500MS 500
#define TASK_INTERVAL_1000MS 1000

int getSimulatedSpeed() {
    return rand() % 121; // 0 - 120 km/h
}

void sendCANMessage(int speed) {
    // Yellow color
    printf("\x1b[33mSending CAN Msg | ID: 0x120 | Payload: Speed = %d km/h\x1b[0m\n", speed);
}

int main() {
    srand((unsigned int)time(NULL));

    unsigned long lastSpeedRead = 0;
    unsigned long lastCANSend = 0;

    int currentSpeed = 0;
    unsigned long timeElapsed = 0;

    printf("Starting Vehicle Speed Monitor Simulation...\n");

    while (timeElapsed < 10000) {  // Run for 10 seconds
        if (timeElapsed - lastSpeedRead >= TASK_INTERVAL_500MS) {
            currentSpeed = getSimulatedSpeed();
            // Cyan color
            printf("\x1b[36m[%.2fs] Speed Sensor: %d km/h\x1b[0m\n", timeElapsed / 1000.0, currentSpeed);
            if (currentSpeed > 100) {
                // Red and bold
                printf("\x1b[1;31mWarning: Over Speeding!\x1b[0m\n");
            }
            lastSpeedRead = timeElapsed;
        }

        if (timeElapsed - lastCANSend >= TASK_INTERVAL_1000MS) {
            sendCANMessage(currentSpeed);
            lastCANSend = timeElapsed;
        }

        Sleep(100);  // Sleep for 100ms (Windows)
        timeElapsed += 100;
    }

    printf("Simulation complete.\n");
    return 0;
}
