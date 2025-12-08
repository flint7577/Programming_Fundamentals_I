/* Use a one-dimensional array to solve the following problem. Read in 20 numbers,
each of which is between 10 and 100, inclusive. As each number is read, validate it
and store it in the array only if it isn’t a duplicate of a number already read. After
reading all the values, display only the unique values that the user entered. Provide
for the “worst case” in which all 20 numbers are different. Use the smallest
possible array to solve this problem. */


#include <iostream>  
using namespace std;

int main() {
    const int SIZE = 20;
    int numbers[SIZE]; // Smallest possible array (size 20 for worst case)  
    int count = 0;     // Tracks unique numbers  

    // Read 20 valid numbers (10-100)  
    for (int i = 0; i < SIZE; ++i) {
        int num;
        bool valid = false;

        // Validate input is between 10 and 100  
        do {
            cout << "Enter number " << i + 1 << " (10-100): ";
            cin >> num;
            if (num >= 10 && num <= 100) valid = true;
            else cout << "Invalid. Try again.\n";
        } while (!valid);

        // Check for duplicates  
        bool duplicate = false;
        for (int j = 0; j < count; ++j) {
            if (numbers[j] == num) {
                duplicate = true;
                break;
            }
        }

        // Store if unique  
        if (!duplicate) {
            numbers[count] = num;
            count++;
        }
    }

    // Display unique numbers  
    cout << "\nUnique values: ";
    for (int i = 0; i < count; ++i) {
        cout << numbers[i] << " ";
    }

    return 0;
}