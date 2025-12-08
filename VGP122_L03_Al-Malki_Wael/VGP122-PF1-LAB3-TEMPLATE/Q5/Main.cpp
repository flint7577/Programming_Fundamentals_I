/* Implement the following integer functions:
a. Function celsius returns the Celsius equivalent of a Fahrenheit temperature.
b. Function fahrenheit returns the Fahrenheit equivalent of a Celsius
temperature.
c. Use these functions to write a program that prints charts showing the
Fahrenheit equivalents of all Celsius temperatures from 0 to 100 degrees, and
the Celsius equivalents of all Fahrenheit temperatures from 32 to 212 degrees.

Print the outputs in a neat tabular format that minimizes the number of lines of
output while remaining readable. */


#include <iostream>
#include <iomanip> // For setprecision and fixed
using namespace std;

// Converts Fahrenheit to Celsius
double celsius(double f) {
    return (f - 32) * 5.0 / 9.0;
}

// Converts Celsius to Fahrenheit
double fahrenheit(double c) {
    return c * 9.0 / 5.0 + 32;
}

int main() {
    // Set decimal precision to 1 place
    cout << fixed << setprecision(1);

    // Print table headers
    cout << "Celsius\t\tFahrenheit\t|\tFahrenheit\tCelsius\n";
    cout << "------------------------------------------------------------\n";

    // Loop through Celsius (0-100) and Fahrenheit (32-212) in steps of 10 and 18
    for (int c = 0, f = 32; c <= 100; c += 10, f += 18) {
        cout << c << "\t\t" << fahrenheit(c)
            << "\t\t|\t" << f << "\t\t" << celsius(f) << endl;
    }

    return 0;
}