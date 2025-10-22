#include <iostream>
using namespace std;

int main() {
    
    int num1 = 0;
    int num2 = 0;

    std::cout << "Enter a number: ";
    std::cin >> num1;

    std::cout << "Enter a second number: ";
    std::cin >> num2;

    int mediator = num1;
    num1 = num2;
    num2 = mediator;

    std::cout << "The value of the first variable is " << num1 << std::endl;
    std::cout << "The value of the second variable is " << num2 << std::endl;


    return 0;
}