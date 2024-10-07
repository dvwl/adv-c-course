---
lab:
    title: 'Smart Home Memory Optimisation'
---
# Module 02b: Smart Home Memory Optimisation

## Overview

In this exercise, you are tasked with managing a smart home system where multiple appliances (lights, fan, thermostat, etc.) can be turned on or off using flags in a single byte. This time around, you need to develop a generic way to handle multiple types of devices efficiently.

The `turnOn`, `turnOff`, `checkStatus` functions currently takes `unsigned char* devices`, which needs to be generalised to work with different types of devices. Additionally, you want to optimize the memory used by the devices to handle a large number of them in a memory-constrained environment.

### Exercise Instructions
1. Define a base device structure. Instead of using `unsigned char*`.
2. Extend the SmartLight Struct. You may insert other additional structs.
3. Generalise the `turnOn`, `turnOff`, and `checkStatus` functions.
4. Optimise memory usage.

**Example Code:**
```c
#include <stdio.h>

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
}

void turnOff(Device * device, unsigned char flag) {
    // insert code
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
Continue to enhance your smart home system by recalling module 1, such header and source files. Stay curious and keep experimenting!

Happy coding!
