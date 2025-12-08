/* Write a program that inputs a series of integers and passes them one at a time to
function isEven, which uses the modulus operator to determine whether an integer
is even. The function should take an integer argument and return true if the integer
is even and false otherwise. */


#include <iostream>  
using namespace std;

// Function to check if a number is even  
bool isEven(int num) {
    return (num % 2 == 0);
}

int main() {
    int num;
    cout << "Enter integers (Ctrl+Z/Ctrl+D to stop):\n";

    // Read integers until user stops  
    while (cin >> num) {
        if (isEven(num)) {
            cout << num << " is even.\n";
        }
        else {
            cout << num << " is odd.\n";
        }
    }

    return 0;
}