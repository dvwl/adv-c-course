#include <stdio.h>
#include <string.h>
#include "include/device.h"

// in your generated tasks.json, don't forget to include device.c into the build:
// "${workspaceFolder}/source/device.c", // Compile device.c

int main(void * args) {
	// // Step 1: Declare and initialize a SmartLight object
    // SmartLight myLight;

    // // Initialize base device fields
    // myLight.base.deviceID = 1;
    // strcpy(myLight.base.status, "ON");
    // myLight.base.deviceType = LIGHT;

    // Declare and initialize the SmartLight
    SmartLight myLight = { 
        .base = { .deviceID = 1, .status = "ON", .deviceType = LIGHT },
        .brightness = 75,
        .color = "Cool White"
    };

    // Initialize SmartLight-specific fields
    myLight.brightness = 75;
    strcpy(myLight.color, "Warm White");

    // Step 2: Call checkStatus by passing the base struct from SmartLight
    checkStatus(&myLight.base);

    // Additional print to show SmartLight-specific fields
    printf("Brightness: %d\n", myLight.brightness);
    printf("Color: %s\n", myLight.color);

	return 0;
}
