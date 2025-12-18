/* Create a SavingsAccount class. Use a static data member annualInterestRate to store the
annual interest rate for each of the savers. Each member of the class contains a private data
member savingsBalance indicating the amount the saver currently has on deposit. Provide
member function calculateMonthlyInterest that calculates the monthly interest by multiplying the
savingsBalance by annualInterestRate divided by 12; this interest should be added to
savingsBalance. Provide a static member function modifyInterestRate that sets the static
annualInterestRate to a new value. Write a driver program to test class SavingsAccount.
Instantiate two different objects of class SavingsAccount, saver1 and saver2, with balances of
$2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the
monthly interest and print the new balances for each of the savers. Then set the
annualInterestRate to 4 percent, calculate the next month�s interest and print the new balances for
each of the savers. */

#include <iostream>
using namespace std;

class SavingsAccount {
private:
    static double annualInterestRate;
    double savingsBalance;

public:
    SavingsAccount(double balance) {
        savingsBalance = balance;
    }

    void calculateMonthlyInterest() {
        savingsBalance += savingsBalance * (annualInterestRate / 12);
    }

    static void modifyInterestRate(double rate) {
        annualInterestRate = rate;
    }

    double getBalance() {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.0;

int main() {

    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << saver1.getBalance() << endl;
    cout << saver2.getBalance() << endl;

    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << saver1.getBalance() << endl;
    cout << saver2.getBalance() << endl;

    return 0;
}
