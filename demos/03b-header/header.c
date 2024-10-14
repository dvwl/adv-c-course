#include <stdio.h>
#include "inc/complex.h"

int main (void) {
	Complex c1 = {
		.a = 1,
		.b = 2,
	};

	printf("%d", c1.a);
	return 0;
}