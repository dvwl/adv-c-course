#include <stdio.h>
#define FLAG_READ 0x01  // 0001
#define FLAG_WRITE 0x02 // 0010
#define FLAG_EXEC 0x04  // 0100

void checkPermissions(unsigned char permissions) {
    if (permissions & FLAG_READ) {
        printf("Read permission granted\n");
    }
    if (permissions & FLAG_WRITE) {
        printf("Write permission granted\n"); 
    }   
    if (permissions & FLAG_EXEC) {
        printf("Execute permission granted\n");
    }
}

// Function to return multiple values using pointers
void calculate(int a, int b, int *sum, int *product) {
    *sum = a + b;      // Assign sum value via pointer
    *product = a * b;  // Assign product value via pointer
}

typedef struct Results {
    int sum;
    int product;
} Results;

// Bitwise for addition
int bitwiseAddRecursive(int a, int b) {
    // Base case: if there's no carry, return the sum (a)
    if (b == 0) {
        return a;
    }

    // Calculate the carry
    int carry = a & b;

    // Calculate the sum without carry
    int sum = a ^ b;

    // Recursively call with the new sum and carry shifted left
    return bitwiseAddRecursive(sum, carry << 1);
}

// Function to multiply two numbers using bitwise operations
int bitwiseMultiply(int a, int b) {
    int result = 0;  // Result of multiplication
    while (b > 0) {
        // If the current bit of b is set (b & 1 == 1), add a to the result
        if (b & 1) {
            result = result + a;
        }
        
        // Shift a left (equivalent to multiplying by 2)
        a <<= 1;
        
        // Shift b right (equivalent to dividing by 2 and moving to the next bit)
        b >>= 1;
    }
    return result;
}

// Function to return multiple values using struct
Results calculateWithBitwise(int a, int b) {
    Results res;
    res.sum = bitwiseAddRecursive(a, b);
    res.product = bitwiseMultiply(a, b);
    return res;
}

int main() {
    // flags
    unsigned char userPermissions = FLAG_READ | FLAG_WRITE;    
    checkPermissions(userPermissions);

    // shift operators
	int x = 5, y = 8;
	int leftShift = x << 1;
	int rightShift = y >> 1;

	printf("x: %d, y: %d\n", leftShift, rightShift);

    // parse by reference
	int sum = 0, product = 0;
	calculate(x, y, &sum, &product);
	printf("sum: %d, product: %d\n", sum, product);

    // return a struct
    Results result = calculateWithBitwise(x, y);
    printf("sum: %d, product: %d\n", result.sum, result.product);

    return 0;
}
