/* Develop a C++ program that will determine whether a department-store customer has
exceeded the credit limit on a charge account. For each customer, the following facts are
available:
a. Account number (an integer)
b. Balance at the beginning of the month
c. Total of all items charged by this customer this month
d. Total of all credits applied to this customer's account this month
e. Allowed credit limit

The program should use a while statement to input each of these facts, calculate the new
balance (= beginning balance + charges – credits) and determine whether the new balance
exceeds the customer’s credit limit. For those customers whose credit limit is exceeded, the
program should display the customer’s account number, credit limit, new balance and the
message "Credit Limit Exceeded."

Enter account number (or -1 to quit): 100
Enter beginning balance: 5394.78
Enter total charges: 1000.00
Enter total credits: 500.00
Enter credit limit: 5500.00
New balance is 5894.78
Account: 100
Credit limit: 5500.00
Balance: 5894.78
Credit Limit Exceeded.
Enter Account Number (or -1 to quit): 200
Enter beginning balance: 1000.00
Enter total charges: 123.45
Enter total credits: 321.00
Enter credit limit: 1500.00
New balance is 802.45
Enter Account Number (or -1 to quit): -1 */


#include <iostream>
using namespace std;

int main() {

	int accountNumber = 0;

	cout << "Enter account number (or -1 to quit): ";
	cin >> accountNumber;

	while (accountNumber != -1) {

		double beginningBalance = 0;
		double totalCharges = 0;
		double totalCredits = 0;
		double creditLimit = 0;

		cout << "Enter beginning balance: ";
		cin >> beginningBalance;

		cout << "Enter total charges: ";
		cin >> totalCharges;

		cout << "Enter total credits: ";
		cin >> totalCredits;

		cout << "Enter credit limit: ";
		cin >> creditLimit;

		float newBalance = beginningBalance + totalCharges - totalCredits;

		cout << "New balance is " << newBalance << endl;

		//Account summary
			cout << "Account: " << accountNumber << endl;
			cout << "Credit limit: " << creditLimit << endl;
			cout << "Balance: " << newBalance << endl;

		//Warning for exceeding credit limit
		if (newBalance > creditLimit) {

			cout << "Credit Limit Exceeded." << endl;

		}

		cout << "Enter account number (or -1 to quit): ";
		cin >> accountNumber;
		
	}
	
	return 0;
}
