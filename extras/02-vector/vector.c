// While C does not have a built-in vector data type,
// we can replicate vector-like behavior using structures
// and dynamic memory allocation. 
// By implementing operations such as pushing, popping, 
// and accessing elements, we can create a pseudo-vector 
// that mimics the behavior of C++ vectors. 
// This approach provides a flexible and efficient way to 
// manage dynamic arrays in C programming.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a generic vector structure
typedef struct {
    void** items;     // Array of void pointers to store elements
    size_t capacity;  // Maximum capacity of the vector
    size_t size;      // Current number of elements in the vector
} Vector;

// Function to initialize a vector with a given initial capacity
void initVector(Vector* vector, size_t initialCapacity) {
    vector->items = (void**)malloc(sizeof(void*) * initialCapacity);
    vector->capacity = initialCapacity;
    vector->size = 0;
}

// Function to resize the vector when it runs out of capacity
void resizeVector(Vector* vector, size_t newCapacity) {
    vector->items = (void**)realloc(vector->items, sizeof(void*) * newCapacity);
    vector->capacity = newCapacity;
}

// Function to add an element to the vector
void pushToVector(Vector* vector, void* item) {
    if (vector->size == vector->capacity) {
        // Double the capacity if vector is full
        resizeVector(vector, vector->capacity * 2);
    }
    vector->items[vector->size] = item;
    vector->size++;
}

// Function to get an element from the vector at a given index
void* getFromVector(Vector* vector, size_t index) {
    if (index >= vector->size) {
        printf("Index out of bounds\n");
        return NULL;
    }
    return vector->items[index];
}

// Function to free the memory used by the vector
void freeVector(Vector* vector) {
    free(vector->items);
}

// Example print function for integers
void printInt(void* data) {
    printf("%d ", *(int*)data);
}

// Example print function for custom structs
typedef struct {
    int age;
    char name[20];
} Person;

void printPerson(void* data) {
    Person* person = (Person*)data;
    printf("name: %s, age: %d ", person->name, person->age);
}

// Function to print vector elements using a function pointer
typedef void (*PrintFunc)(void*);

void printVector(Vector* vector, PrintFunc printFunc) {
    for (size_t i = 0; i < vector->size; i++) {
        printFunc(vector->items[i]);
    }
    printf("\n");
}

int main() {
    Vector intVector;
    initVector(&intVector, 2);  // Initialize with capacity of 2

    // Add integers to the vector
    int a = 10, b = 20, c = 30;
    pushToVector(&intVector, &a);
    pushToVector(&intVector, &b);
    pushToVector(&intVector, &c);

    printf("Integer vector: ");
    printVector(&intVector, printInt);  // Pass printInt as the print function

    // Create a vector of Person structs
    Vector personVector;
    initVector(&personVector, 2);  // Initialize with capacity of 2

    // Add persons to the vector
    Person person1 = {25, "Alice"};
    Person person2 = {30, "Bob"};
    pushToVector(&personVector, &person1);
    pushToVector(&personVector, &person2);

    printf("Person vector: ");
    printVector(&personVector, printPerson);  // Pass printPerson as the print function

    // Free memory
    freeVector(&intVector);
    freeVector(&personVector);

    return 0;
}
