/* Write a single C++ statement or line that accomplishes each of the following:
a. Print the message "Enter two numbers".
b. Input two integer values from the keyboard into integer variables b and c.
c. Assign the product of variables b and c to variable a.
d. Print the value of variable a. */

#include <iostream>

int main() { int a = 0; int b = 0; int c = 0; std::cout << "Enter two numbers" << std::endl; std::cin >> b >> c; a = b*c; std::cout << a << std::endl; return 0;}