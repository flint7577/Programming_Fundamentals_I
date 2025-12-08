/* Factorials are used frequently in probability problems. The factorial of a
positive integer n (written n! and pronounced “n factorial”) is equal to the product
of the positive integers from 1 to n. Write an application that calculates the
factorials of 1 through 20. Use type long. Display the results in tabular format. */

#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	cout << left << setw(10) << "Number" << "Factorial" << endl;
	cout << "------------------------" << endl;
	long factorial = 1;
	for (int i = 1; i <= 20; ++i) {
		factorial *= i; // calculate factorial
		cout << left << setw(10) << i << factorial << endl; // display number and its factorial
	}
	return 0;
}