#include <iostream>

int main()
{
	// Print the size (in bytes) of an integer variable
	std::cout << "The size of an integer variable is " << sizeof(int) << " bytes" << std::endl;

	// Print the size (in bytes) of a short integer variable
	std::cout << "The size of a short integer variable is " << sizeof(short) << " bytes" << std::endl;

	// Print the size (in bytes) of a long long integer variable
	std::cout << "The size of a long integer variable is " << sizeof(long long) << " bytes" << std::endl;

	// Print the size (in bytes) of a character variable
	std::cout << "The size of a character variable is " << sizeof(char) << " bytes" << std::endl;

	// Print the size (in bytes) of a floating-point variable
	std::cout << "The size of a floating-point variable is " << sizeof(float) << " bytes" << std::endl;

	// Print the size (in bytes) of a double variable
	std::cout << "The size of a double variable is " << sizeof(double) << " bytes" << std::endl;

	// Print the size (in bytes) of a bool variable
	std::cout << "The size of a bool variable is " << sizeof(bool) << " bytes" << std::endl;

	return 0;
}
