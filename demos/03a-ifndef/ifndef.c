#include <stdio.h>
// #define YEARS_OLD 12
#ifndef YEARS_OLD
#define YEARS_OLD 10
#endif
#define DEBUG

int main()
{
	#ifndef DEBUG
    printf("I am %d years old.", YEARS_OLD);
	#else
	printf("Production mode.");
	#endif

    return 0;
}
