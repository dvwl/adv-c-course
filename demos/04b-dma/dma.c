#include <stdio.h>

#define SIZE 10

void create(int* p_num, int size) {
    // Step 1: Dynamically allocate memory for the array
    p_num = (int*)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (p_num == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Step 2: Initialize all elements of the array to 1 (for example)
    for (int i = 0; i < size; i++) {
        p_num[i] = 1;
    }

    // Step 3: Perform your algorithm here
    // Example: Print the array to verify initialization
    printf("Array initialized with 1:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", p_num[i]);
    }
    printf("\n");

    // Step 4: Free the dynamically allocated memory
    free(p_num);
}

int main(void *args) {
	// dynamic memory allocation
    int* a = NULL;  // Pointer to pass to the function
    create(a, SIZE);
}
