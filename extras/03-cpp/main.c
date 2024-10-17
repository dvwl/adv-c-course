// main.c
#include <stdio.h>

// Declare the C-wrapped functions for the C++ class
#ifdef __cplusplus
extern "C"
{
#endif

	// Function declarations
	typedef struct MyClass MyClass;

	MyClass *MyClass_new(int value);
	void MyClass_delete(MyClass *instance);
	void MyClass_setValue(MyClass *instance, int value);
	int MyClass_getValue(const MyClass *instance);

#ifdef __cplusplus
}
#endif

int main()
{
	// Create an instance of MyClass
	MyClass *obj = MyClass_new(42);

	// Print the initial value
	printf("Initial value: %d\n", MyClass_getValue(obj));

	// Set a new value
	MyClass_setValue(obj, 99);

	// Print the updated value
	printf("Updated value: %d\n", MyClass_getValue(obj));

	// Clean up
	MyClass_delete(obj);

	return 0;
}
