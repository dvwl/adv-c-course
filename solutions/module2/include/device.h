#ifndef _DEVICE_H
#define _DEVICE_H

#define LIGHT 0x01
#define FAN 0x02

// Define a base struct for generic devices
typedef struct Device {
    int deviceID;               // Unique identifier for the device
    char status[10];            // Status of the device (e.g., "ON", "OFF")
    unsigned char deviceType;   // Store flags for various statuses (lights, fan, thermostat)
} Device;

// Define a struct for a smart light device
typedef struct SmartLight {
    Device base;                // Base device properties
    int brightness;             // Brightness level (0 to 100)
    char color[20];             // Color of the light (e.g., "Warm White", "Cool White")
} SmartLight;

// Check Device Status
void checkStatus(Device* device);

#endif
