---
lab:
    title: 'Binary File I/O: Efficient Data Handling'
---
# Module 03a: Binary File I/O - Efficient Data Handling

## Overview

In this module, you will explore binary file I/O in C. The focus is on applying best practices to efficiently read from and write to binary files, using conditional compilation to switch between writing to text or binary format. This base code offers you a starting point to experiment with file handling techniques.

### Exercise Instructions
1. Implement functionality to save and load data to and from a binary file.
2. Use `#ifdef BINARY_MODE` to toggle between binary and text file formats.
3. Ensure efficient handling of file pointers and buffers.

**Example Code:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define BINARY_MODE to switch between text and binary file operations
//#define BINARY_MODE            // Comment out to use text file I/O

// Define a struct to store data (could be any type of data, e.g., sensor readings, scores, etc.)
typedef struct {
    int id;
    char description[30];
    float value;                  // Some data value to be stored (e.g., score, temperature)
} DataItem;

void writeDataToFile(DataItem* items, int itemCount, const char* fileName) {
    FILE *file;
    
    #ifdef BINARY_MODE
        // Open file in binary mode
    #else
        // Open file in text mode
    #endif

    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        #ifdef BINARY_MODE
            fwrite(&items[i], sizeof(DataItem), 1, file);    // Write in binary
        #else
            fprintf(file, "%d,%s,%.2f\n", items[i].id, items[i].description, items[i].value);    // Write in text
        #endif
    }

    fclose(file);
}

void readDataFromFile(const char* fileName) {
    FILE *file;
    
    #ifdef BINARY_MODE
        // Open file in binary mode
    #else
        // Open file in text mode
    #endif

    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    DataItem item;

    #ifdef BINARY_MODE
        while (fread(&item, sizeof(DataItem), 1, file)) {
            printf("ID: %d, Description: %s, Value: %.2f\n", item.id, item.description, item.value);
        }
    #else
        while (fscanf(file, "%d,%29[^,],%f", &item.id, item.description, &item.value) != EOF) {
            printf("ID: %d, Description: %s, Value: %.2f\n", item.id, item.description, item.value);
        }
    #endif

    fclose(file);
}

int main() {
    DataItem items[] = {
        {1, "Sensor 1", 24.5},
        {2, "Sensor 2", 30.1},
        {3, "Sensor 3", 22.8}
    };

    writeDataToFile(items, 3, "datafile.dat");

    printf("Reading data from file:\n");
    readDataFromFile("datafile.dat");

    return 0;
}
```

**Next Steps:**
1. Experiment by toggling #define BINARY_MODE and observing how the program behaves with text and binary formats.
2. Use larger datasets and monitor memory usage to practice optimizing file I/O.

Happy coding!
