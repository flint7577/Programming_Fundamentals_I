/* Write an application that finds the smallest of several integers. Assume that the
first value read specifies the number of values to input from the user. */

#include <iostream>
using namespace std;

int main() {

	//sanity check
	int numberOfValues;

cout << "Enter the number of values to compare: ";
cin >> numberOfValues;


if (numberOfValues <= 0) {

	cout << "Please enter a positive integer for the number of values." << endl;

	return 1;
}

//actual code
int smallestValue;
cin >> smallestValue;
for (int i = 2; i <= numberOfValues; ++i) {
	int currentValue;
	cin >> currentValue;
	if (currentValue < smallestValue) {
		smallestValue = currentValue;
	}
}
cout << "The smallest value is: " << smallestValue << endl;
return 0;
}