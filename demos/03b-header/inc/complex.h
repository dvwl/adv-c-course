#ifndef _COMPLEX_H   /* only include once */
#define _COMPLEX_H
/* global constants */
/* structure and function declaration */

typedef struct Complex {
	int a;
	int b;
} Complex;

Complex addComplex(Complex c1, Complex c2);

#endif
