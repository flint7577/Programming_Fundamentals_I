/* Write a program to find the factorial of a given number using pointers. */

#include <iostream>
using namespace std;

int main() {

	int userInt = 0;

	//sanity check
	cout << "enter a number" << endl;
	cin >> userInt;


	//actual code
	long factorial = 1;
	long* pntr = &factorial;

	for (int i = 1; i <= userInt; i++) {

		*pntr = (*pntr) * i;

	}

	cout << *pntr << endl;

	delete[] pntr;
	return 0;
}