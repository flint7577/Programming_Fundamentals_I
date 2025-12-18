/* Create a class called Rational for performing arithmetic with fractions. Write a program to test
your class. Use integer variables to represent the private data of the class� the numerator and the
denominator. Provide a constructor that enables an object of this class to be initialized when it�s
declared. The constructor should contain default values in case no initializers are provided and
should store the fraction in reduced form.

For example, the fraction 2/4 would be stored in the object as 1 in the numerator and 2 in the denominator. 

Provide public member functions that perform each of the following tasks:
a. add�Adds two Rational numbers. The result should be stored in reduced form.
b. subtract�Subtracts two Rational numbers. Store the result in reduced form.
c. multiply�Multiplies two Rational numbers. Store the result in reduced form.
d. divide�Divides two Rational numbers. The result should be stored in reduced form.
e. toRationalString�Returns a string representation of a Rational number in the form a/b, where
a is the numerator and b is the denominator.
f. toDouble�Returns the Rational number as a double. */

#include <iostream>
#include <string>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void reduce() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Rational(int n = 0, int d = 1) {
        numerator = n;
        denominator = (d == 0) ? 1 : d;
        reduce();
    }

    Rational add(Rational r) {
        return Rational(
            numerator * r.denominator + r.numerator * denominator,
            denominator * r.denominator
        );
    }

    Rational subtract(Rational r) {
        return Rational(
            numerator * r.denominator - r.numerator * denominator,
            denominator * r.denominator
        );
    }

    Rational multiply(Rational r) {
        return Rational(
            numerator * r.numerator,
            denominator * r.denominator
        );
    }

    Rational divide(Rational r) {
        return Rational(
            numerator * r.denominator,
            denominator * r.numerator
        );
    }

    string toRationalString() {
        return to_string(numerator) + "/" + to_string(denominator);
    }

    double toDouble() {
        return static_cast<double>(numerator) / denominator;
    }
};

int main() {

    Rational r1(2, 4);
    Rational r2(3, 5);

    cout << r1.add(r2).toRationalString() << endl;
    cout << r1.subtract(r2).toRationalString() << endl;
    cout << r1.multiply(r2).toRationalString() << endl;
    cout << r1.divide(r2).toRationalString() << endl;
    cout << r1.toDouble() << endl;

    return 0;
}
