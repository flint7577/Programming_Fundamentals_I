/* Create a RationalNumber(fractions) class like the one in Exercise 9.6.
Provide the following capabilities:
a. Create the class as a template class
b. Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
fractions that are not in reduced form and avoids negative denominators.
c. Overload the addition, subtraction, multiplication and division operators for this class.
d. Overload the relational and equality operators for this class. */


#include <iostream>
using namespace std;

template <typename T>
class RationalNumber {
private:
    T numerator;
    T denominator;

    T absVal(T x) { return (x < 0) ? -x : x; }

    T gcd(T a, T b) {
        a = absVal(a);
        b = absVal(b);
        while (b != 0) {
            T t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void reduce() {
        if (denominator == 0) denominator = 1;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        T g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    RationalNumber(T n = 0, T d = 1) : numerator(n), denominator(d) {
        if (denominator == 0) denominator = 1;
        reduce();
    }

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber& r) const {
        return RationalNumber(numerator * r.denominator + r.numerator * denominator,
                              denominator * r.denominator);
    }

    RationalNumber operator-(const RationalNumber& r) const {
        return RationalNumber(numerator * r.denominator - r.numerator * denominator,
                              denominator * r.denominator);
    }

    RationalNumber operator*(const RationalNumber& r) const {
        return RationalNumber(numerator * r.numerator,
                              denominator * r.denominator);
    }

    RationalNumber operator/(const RationalNumber& r) const {
        return RationalNumber(numerator * r.denominator,
                              denominator * r.numerator);
    }

    // Relational & equality operators
    bool operator==(const RationalNumber& r) const {
        return numerator == r.numerator && denominator == r.denominator;
    }

    bool operator!=(const RationalNumber& r) const {
        return !(*this == r);
    }

    bool operator<(const RationalNumber& r) const {
        return numerator * r.denominator < r.numerator * denominator;
    }

    bool operator>(const RationalNumber& r) const {
        return r < *this;
    }

    bool operator<=(const RationalNumber& r) const {
        return !(*this > r);
    }

    bool operator>=(const RationalNumber& r) const {
        return !(*this < r);
    }

    void print() const {
        cout << numerator << "/" << denominator;
    }
};

int main() {

    RationalNumber<int> a(2, 4);
    RationalNumber<int> b(3, 5);

    (a + b).print(); cout << endl;
    (a - b).print(); cout << endl;
    (a * b).print(); cout << endl;
    (a / b).print(); cout << endl;

    cout << (a == b) << endl;
    cout << (a < b) << endl;

    return 0;
}
