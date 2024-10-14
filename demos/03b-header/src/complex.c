#include "../inc/complex.h"

Complex addComplex(Complex c1, Complex c2) {
	Complex c = {
		.a = c1.a + c2.a,
		.b = c1.b + c2.b,
	};
	return c;
}
