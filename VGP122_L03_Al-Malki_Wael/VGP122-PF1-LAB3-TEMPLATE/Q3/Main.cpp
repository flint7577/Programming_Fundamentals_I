/* Define a function hypotenuse that calculates the hypotenuse of a right triangle
when the other two sides are given. The function should take two double arguments
and return the hypotenuse as a double. Use this function in a program to determine
the hypotenuse for each of the triangles shown below. 

Triangle	Side 1		Side 2
1			3.0			4.0
2			5.0			12.0
3			8.0			15.0 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to calculate hypotenuse
double hypotenuse(double a, double b) {
    return sqrt(a * a + b * b);
}

int main() {
    // Print table header
    cout << "Triangle\tSide 1\t\tSide 2\t\tHypotenuse" << endl;

    // Fixed decimal formatting (1 decimal place)
    cout << fixed << setprecision(1);

    // Process Triangle 1 (3.0, 4.0)
    cout << "1\t\t3.0\t\t4.0\t\t" << hypotenuse(3.0, 4.0) << endl;

    // Process Triangle 2 (5.0, 12.0)
    cout << "2\t\t5.0\t\t12.0\t\t" << hypotenuse(5.0, 12.0) << endl;

    // Process Triangle 3 (8.0, 15.0)
    cout << "3\t\t8.0\t\t15.0\t\t" << hypotenuse(8.0, 15.0) << endl;

    return 0;
}