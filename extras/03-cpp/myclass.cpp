// myclass.cpp
#include <iostream>

// C++ class
class MyClass
{
public:
	MyClass(int value) : value(value) {}

	void setValue(int val)
	{
		value = val;
	}

	int getValue() const
	{
		return value;
	}

private:
	int value;
};

// Expose the class via C-style functions
extern "C"
{
	// Create an instance of the class
	MyClass *MyClass_new(int value)
	{
		return new MyClass(value);
	}

	// Destroy the instance
	void MyClass_delete(MyClass *instance)
	{
		delete instance;
	}

	// Set the value
	void MyClass_setValue(MyClass *instance, int value)
	{
		instance->setValue(value);
	}

	// Get the value
	int MyClass_getValue(const MyClass *instance)
	{
		return instance->getValue();
	}
}
