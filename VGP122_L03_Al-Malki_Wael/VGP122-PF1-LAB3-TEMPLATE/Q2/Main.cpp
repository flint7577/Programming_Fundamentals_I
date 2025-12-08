/* Function floor can be used to round a number to a specific decimal place. The
statement y = floor(x * 10 + 0.5) / 10; rounds x to the tenths position (the
first position to the right of the decimal point). The statement y = floor(x * 100
+ 0.5) / 100; rounds x to the hundredths position (the second position to the
right of the decimal point). Write a program that defines four functions to round a
number x in various ways:
a. roundToInteger(number)
b. roundToTenths(number)
c. roundToHundredths(number)
d. roundToThousandths(number)

For each value read, your program should print the original value, the number
rounded to the nearest integer, the number rounded to the nearest tenth, the
number rounded to the nearest hundredth and the number rounded to the nearest
thousandth. */

#include <iostream>
#include <cmath>

using namespace std;

double rInt(double x) { return floor(x + 0.5); }
double rTen(double x) { return floor(x * 10 + 0.5) / 10; }
double rHundr(double x) { return floor(x * 100 + 0.5) / 100; }
double rThous(double x) { return floor(x * 1000 + 0.5) / 1000; }

int main()
{
	double num;
	cout << "Enter numbers:\n";

	while (cin >> num)
	{
		cout << "Original: " << num << endl;

		cout << "Integer: " << rInt(num) << endl;
		cout << "Tenths: " << rTen(num) << endl;
		cout << "Hundredths: " << rHundr(num) << endl;
		cout << "Thousandths: " << rThous(num) << endl;
	}

	return 0;

}