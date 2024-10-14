#include <stdio.h>

typedef int (*Operation)(int, int);

typedef struct {
	int result;
	Operation opt;
} Calculator;

int add(int a, int b) { 
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int myCalculation(int a, int b, int c) {
	printf("%i, %i, %i", a, b, c);
	return a * b - c;
}

int main (void * args) {
	Calculator calc;    // Create a Calculator instance
    calc.result = 0;    // Initialize the result
	calc.opt - add;		//  Perform addition
    // calc.opt = myCalculation;     // Can't do this.
    calc.result = calc.opt(5, 3);   // Call the function through the pointer
    printf("Addition result: %d\n", calc.result);
}