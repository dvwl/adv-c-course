#include <stdio.h>
#include "../include/device.h"

// Function to check the status of a generic device
void checkStatus(Device* device) {
    printf("Device ID: %d\n", device->deviceID);
    printf("Device Status: %s\n", device->status);

    // Assuming you have some flags or types defined for different devices
    if (device->deviceType & LIGHT) {
        printf("This is a light device.\n");
    } else if (device->deviceType & FAN) {
        printf("This is a fan device.\n");
    }
    // Add more checks for other types if needed
}

// Add more functions here

