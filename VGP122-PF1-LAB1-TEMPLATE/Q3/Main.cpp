/* Write a program that asks the user to enter two numbers, obtains the two
numbers from the user and prints the sum, product, difference, and quotient of the
two numbers. */

#include <iostream>
using namespace std;

int main() {
    int num1 = 0;
    int num2 = 0;

    std::cout << "Enter two numbers" << std::endl;

    std::cin >> num1 >> num2;
    
    std::cout << "Sum = " << num1 + num2 << std::endl;
    std::cout << "Product = " << num1 * num2 << std::endl;
    std::cout << "Difference = " << num1 - num2 << std::endl;
    std::cout << "Quotient = " << num1 / num2 << std::endl;
    return 0;
}