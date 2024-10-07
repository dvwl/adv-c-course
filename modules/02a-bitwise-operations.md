---
lab:
    title: 'Smart Home Bitwise Operations'
---
# Module 02a: Smart Home Bitwise Operations

## Overview

In this exercise, you are tasked with managing a smart home system where multiple appliances (lights, fan, thermostat, etc.) can be turned on or off using flags in a single byte.

### Exercise Instructions
1. Define bitwise flags for each appliance (e.g., `light = 0x01`, `fan = 0x02`, etc.).
2. Write a function to turn on or off each appliance using bitwise operations.
3. Write a function to check the current status of the appliances.
4. Optimise memory usage by ensuring each appliance's state is stored in a single byte.

**Example Code:**
```c
#include <stdio.h>

// define flags

void turnOn(unsigned char* devices, unsigned char flag) {
    // insert code
}

void turnOff(unsigned char* devices, unsigned char flag) {
    // insert code
}

void checkStatus(unsigned char devices) {
    if (/*lights condition*/)
        printf("Lights are ON\n");
    if (/*fan condition*/)
        printf("Fan is ON\n");
    if (/*thermostat condition*/)
        printf("Thermostat is ON\n");
}

int main() {
    unsigned char homeDevices = 0;
    
    // Turn on the lights and fan
    turnOn(&homeDevices, LIGHTS);
    turnOn(&homeDevices, FAN);
    
    // Check device status
    checkStatus(homeDevices);
    
    // Turn off the fan
    turnOff(&homeDevices, FAN);
    checkStatus(homeDevices);
    
    return 0;
}
```

**Next Steps:**
Continue to enhance your smart home system by recalling module 1, such header and source files. Stay curious and keep experimenting!

Happy coding!
