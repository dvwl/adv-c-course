---
lab:
    title: 'Memory-Mapped Files and Shared Memory'
---
# Module 03b: Memory-Mapped Files - Optimizing I/O with Shared Memory

## Overview

In this module, you will explore memory-mapped files, focusing on both simple and shared memory-mapped file scenarios on Windows (or Unix). This technique allows files or objects to be treated as part of memory, enabling faster access and more efficient I/O operations.

### Exercise Instructions
1. Implement a simple memory-mapped file using `CreateFileMapping()` and `MapViewOfFile()` (or Unix equivalents).
2. Extend the exercise to demonstrate shared memory across two separate processes.

### Simple Memory-Mapped File
In this part of the exercise, learners will map a file into memory, write data, and then read it back using memory-mapped file techniques.

**Example Code:**
```c
// Include the right library

#define FILENAME "datafile.bin"

void createAndMapFile() {
    HANDLE hFile = CreateFile(
        FILENAME,
        GENERIC_READ | GENERIC_WRITE,
        0,                   // No sharing
        NULL,                // Default security
        CREATE_ALWAYS,       // Create new file
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Error opening file.\n");
        return;
    }

    // Create file mapping object
    HANDLE hMapping = CreateFileMapping(
        hFile,
        NULL,
        PAGE_READWRITE,      // Read/Write access
        0,                   // Maximum object size (high-order DWORD)
        1024,                // Maximum object size (low-order DWORD)
        NULL                 // Name of mapping object
    );

    if (hMapping == NULL) {
        printf("Error creating file mapping.\n");
        CloseHandle(hFile);
        return;
    }

    // Map file into memory
    void* pMapView = MapViewOfFile(
        hMapping,
        FILE_MAP_ALL_ACCESS, // Read/Write access
        0,                   // File offset (high-order DWORD)
        0,                   // File offset (low-order DWORD)
        0                    // Map the entire file
    );

    if (pMapView == NULL) {
        printf("Error mapping view of file.\n");
        CloseHandle(hMapping);
        CloseHandle(hFile);
        return;
    }

    // Write data to the memory-mapped region
    char* data = (char*)pMapView;
    strcpy(data, "Hello, Memory-Mapped File!");

    // Unmap and close handles
    UnmapViewOfFile(pMapView);
    CloseHandle(hMapping);
    CloseHandle(hFile);
}

void readFromMappedFile() {
    HANDLE hFile = CreateFile(
        FILENAME,
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Error opening file.\n");
        return;
    }

    // Open file mapping object
    HANDLE hMapping = CreateFileMapping(
        hFile,
        NULL,
        PAGE_READONLY,
        0,
        0,
        NULL
    );

    if (hMapping == NULL) {
        printf("Error creating file mapping.\n");
        CloseHandle(hFile);
        return;
    }

    // Map file into memory
    void* pMapView = MapViewOfFile(
        hMapping,
        FILE_MAP_READ,
        0,
        0,
        0
    );

    if (pMapView == NULL) {
        printf("Error mapping view of file.\n");
        CloseHandle(hMapping);
        CloseHandle(hFile);
        return;
    }

    // Read from the memory-mapped region
    char* data = (char*)pMapView;
    printf("Data from memory-mapped file: %s\n", data);

    // Unmap and close handles
    UnmapViewOfFile(pMapView);
    CloseHandle(hMapping);
    CloseHandle(hFile);
}

int main() {
    createAndMapFile();
    readFromMappedFile();
    return 0;
}
```

### Shared Memory-Mapped File
Next, you will create a shared memory-mapped file between two processes, allowing them to communicate through the shared memory space.

**Example code:**
```c
#include <windows.h>
#include <stdio.h>

#define SHARED_MEM_SIZE 1024
#define SHARED_MEM_NAME "Local\\MySharedMemory"

// Process 1: Writing to shared memory
void writeToSharedMemory() {
    HANDLE hMapping = CreateFileMapping(
        INVALID_HANDLE_VALUE,      // Use paging file (no file associated)
        NULL,
        PAGE_READWRITE,
        0,
        SHARED_MEM_SIZE,
        SHARED_MEM_NAME            // Name of shared memory
    );

    if (hMapping == NULL) {
        printf("Error creating shared memory.\n");
        return;
    }

    void* pMapView = MapViewOfFile(
        hMapping,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        SHARED_MEM_SIZE
    );

    if (pMapView == NULL) {
        printf("Error mapping view of shared memory.\n");
        CloseHandle(hMapping);
        return;
    }

    // Write to shared memory
    char* data = (char*)pMapView;
    strcpy(data, "Shared Memory Data!");

    UnmapViewOfFile(pMapView);
    CloseHandle(hMapping);
}

// Process 2: Reading from shared memory
void readFromSharedMemory() {
    HANDLE hMapping = OpenFileMapping(
        FILE_MAP_READ,
        FALSE,
        SHARED_MEM_NAME           // Name of shared memory
    );

    if (hMapping == NULL) {
        printf("Error opening shared memory.\n");
        return;
    }

    void* pMapView = MapViewOfFile(
        hMapping,
        FILE_MAP_READ,
        0,
        0,
        SHARED_MEM_SIZE
    );

    if (pMapView == NULL) {
        printf("Error mapping view of shared memory.\n");
        CloseHandle(hMapping);
        return;
    }

    // Read from shared memory
    char* data = (char*)pMapView;
    printf("Data from shared memory: %s\n", data);

    UnmapViewOfFile(pMapView);
    CloseHandle(hMapping);
}

int main() {
    // In a real scenario, these two functions would run in separate processes.
    // More on multithreading in the next module.
    writeToSharedMemory();
    readFromSharedMemory();
    return 0;
}
```

**Next Steps:**
1. Split the shared memory example into two separate programs and run them concurrently.
2. Experiment with larger memory blocks and observe how memory-mapped files optimize memory usage and I/O efficiency.

Stay curious and keep experimenting!
