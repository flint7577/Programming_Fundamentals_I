#include <iostream>

int main()
{
	// Declare and initialize three integer variables for user inputs and the sum
	int integer1 = 0;
	int integer2 = 0;
	int sum = 0;

	// Prompt the user for the first integer
	std::cout << "Enter first integer: ";
	std::cin >> integer1;

	// Prompt the user for the second integer
	std::cout << "Enter second integer: ";
	std::cin >> integer2;

	// Calculate the sum of the two integers
	sum = integer1 + integer2;

	// Display the result of the addition to the user
	std::cout << "Sum is " << sum << std::endl;

	return 0;
}