#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    //c = sqrt(a^2 + b^2)
    //sqrt(), pow

    double oppLnth = 0;
    double adjLnth = 0;
    double hypLnth = 0;

    std::cout << "Enter the opposite length: ";
    std::cin >> oppLnth;

    std::cout << "Enter the adjacent length: ";
    std::cin >> adjLnth;

    hypLnth = sqrt(pow(oppLnth, 2) + pow(adjLnth, 2));
    std::cout << "The hypotenuse length is " << hypLnth << std::endl;

    return 0;
}