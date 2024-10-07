---
lab:
    title: 'Smart Home Program Mode Control'
---
# Module 02c: Smart Home Program Mode Control

## Overview

In this exercise, you are tasked with introducing a mechanism where the program prints output to a file only when in debug mode. The exercise will you to toggle between production and debugging modes, optimizing memory and I/O usage depending on the mode.

### Exercise Instructions
1. Implement file output when in debug mode using `#define DEBUG`.
2. Ensure no unnecessary file I/O occurs when the program is in production mode.

**Example Code:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define DEBUG mode
#define DEBUG                   // Comment out for production

// Define a base struct for generic devices
typedef struct Device {
    int deviceID;               // Unique identifier for the device
    char status[10];            // Status of the device (e.g., "ON", "OFF")
    unsigned char deviceType;   // Store flags for various statuses (lights, fan, thermostat)
} Device;

// Define a struct for a smart light device
typedef struct SmartLight {
    Device base;                // Inherit base device properties
    int brightness;             // Brightness level (0 to 100)
    char color[20];             // Color of the light (e.g., "Warm White", "Cool White")
} SmartLight;

// Other devices

// Define flags

void turnOn(Device * device, unsigned char flag) {
    // insert code

    // If DEBUG mode is enabled, log to a file
    #ifdef DEBUG

    #endif
}

void turnOff(Device * device, unsigned char flag) {
    // insert code

    // If DEBUG mode is enabled, log to a file
    #ifdef DEBUG
    
    #endif
}

void checkStatus(Device * device) {
    if (/*lights condition*/)
        printf("Lights are ON\n");
    if (/*fan condition*/)
        printf("Fan is ON\n");
    if (/*thermostat condition*/)
        printf("Thermostat is ON\n");
}

int main() {
    SmartLight* lights = // Dynamically allocate memory
    
    // Turn on the lights and fan
    
    // Check device status
    
    // Turn off the fan
    
    return 0;
}
```

**Next Steps:**
Experiment by commenting DEBUG mode. Stay curious and keep experimenting!

Happy coding!
