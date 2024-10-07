---
lab:
    title: 'Building a Smart Home System'
---
# Module 01: Developing Software for Smart Home Devices

## Overview

Welcome to Module 01 of Advanced C Programming! In this module, you'll learn how to define and optimize data structures, write functions, and organize code for a smart home system using C programming. We'll guide you through various exercises and a lab assignment to reinforce your understanding of these concepts.

### Prerequisites
Before beginning these exercises, make sure you have:
- A development environment set up with VS Code or any other preferred code editor.
- Basic understanding of C programming, including functions, structs, and file organization.
- Enthusiasm to dive into the world of IoT and smart devices!

### Exercise 1: Creating a Struct for a Smart Device
In this exercise, you will create a struct to represent a smart device, such as a smart light. You will initialize it with sample data and prepare it for use in the program.

**Instructions:**
1. Define a `struct` for a smart device, such as a smart light.
1. Include fields for attributes like `deviceID`, `status`, `brightness`, and `color`.
1. Initialize the struct with sample data.

**Example Code:**
```c
#include <stdio.h>

// Define a struct for a smart light device
struct SmartLight {
    int deviceID;           // Unique identifier for the device
    char status[10];        // Status of the light (e.g., "ON", "OFF")
    int brightness;         // Brightness level (0 to 100)
    char color[20];         // Color of the light (e.g., "Warm White", "Cool White")
};

int main() {
    // To do: Initialize the struct with sample data
    
    // To do: Print the smart light details

    return 0;
}
```

### Exercise 2: Optimizing Struct Padding
Memory optimization is crucial in embedded systems. In this exercise, you will learn how to arrange struct fields to minimize padding and optimize memory usage.

**Instructions:**
1. Take the struct created in Exercise 1.
1. Rearrange its fields to reduce memory padding.
1. Calculate the memory usage before and after optimization.

**Note:**
To verify the size of a struct in C, you can use the `sizeof` operator.

### Exercise 3: Controlling a Smart Light
Writing functions to control devices is an essential part of smart home systems. In this exercise, you will create a function to control a smart light's state.

**Instructions:**
1. Write a function that changes the smart light's state (e.g., on/off, brightness).
1. Use pass-by-reference to update the state of the light.
1. Test your function by calling it with various input values.

### Exercise 4: Handling Multiple Sensor Data
Smart home systems often read data from multiple sensors. In this exercise, you'll learn how to handle multiple return values using a struct.

**Instructions:**
1. Define a `struct` to hold multiple sensor readings (e.g., temperature, humidity, motion).
1. Write a function that simulates reading these sensors and returns the struct.
1. Display the sensor readings on the console.

### Exercise 5: Organizing Code into Multiple Files
Proper code organization is key for maintainability. In this exercise, you will organize the code you've written so far into multiple files.

**Instructions:**
1. Create separate `.c` and `.h` files for different parts of the code (e.g., main, device control, sensor handling).
1. Refactor the code accordingly and make sure it compiles successfully.

**Note:**
Code that is related to device should be in `device.h/.c`.

### Exercise 6: Creating a Communication Module
Smart devices need to communicate with each other or with a central hub. In this exercise, you will create a communication module for your smart home system.

**Instructions:**
1. Create a new module with separate header (`.h`) and source (`.c`) files.
1. Define functions for sending and receiving data between devices.
1. Integrate this module with your existing codebase.

### Lab Exercise: Creating a Complete Smart Home Program

Now that you've completed the individual exercises, it's time to put everything together!

**Objective:**
Create a complete program that simulates a smart home system, integrating all the concepts you've learned. You'll combine your structs, functions, and modules to build a cohesive and functional system.

**Deliverables:**
- A fully functional program that includes:
 - Structs for different smart devices and sensor data.
 - Functions to control devices and handle sensor readings.
 - Organized code across multiple files with appropriate headers and source files.

**Next Steps:**
Continue to enhance your smart home system by adding new features, such as communication protocols, real-time monitoring, or user-friendly controls. Stay curious and keep experimenting!

Happy coding!
