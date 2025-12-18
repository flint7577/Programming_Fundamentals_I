/* Write a program to find the max value of an integer array data set. The program will ask the user
to input the number of data values in the set and each value. The program prints on screen a
pointer that points to the max value. */

#include <iostream>
using namespace std;

int main() {

	int userArray;


	//sanity check
	cout << "enter number of values" << endl;
	cin >> userArray;

	int* arrayPnt = new int[userArray];

	for (int i = 0; i < userArray; i++) {

		cin >> arrayPnt[i];

	}

	int maxIndex = 0;

	for (int i = 1; i < userArray; i++) {


		if (arrayPnt[i] > arrayPnt[maxIndex]) {

			maxIndex = i;

		}
	}

	int* ptr = &arrayPnt[maxIndex];

	cout << "Max value: " << *ptr << endl;
	cout << "Pointer address: " << ptr << endl;

	delete[] arrayPnt;

	return 0;

}