/* A parking garage charges a $20.00 minimum fee to park for up to three hours. The
garage charges an additional $5.00 per hour for each hour or part thereof in excess
of three hours. The maximum charge for any given 24-hour period is $50.00. Assume
that no car parks for longer than 24 hours at a time.
Write a program that calculates and prints the parking charges for each of three
customers who parked their cars in this garage yesterday. You should enter the
hours parked for each customer. Your program should print the results in a neat
tabular format and should calculate and print the total of yesterday’s receipts. The
program should use the function calculateCharges to determine the charge for each
customer. Your outputs should appear in the following format: 

Car		Hours		Charge
1		1.5			20.0
2		4.0			25.0
3		24.0		50.0
Total	29.5		95.50
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double calculateCharges(double hours)
{
	if (hours <= 3.0)
	{
		return 20.0;
	}


	double extra_hours = ceil(hours - 3.0);

	double charge = 20.0 + (5.0 * extra_hours);

	if (charge > 50.0)
	{
		return 50.0;
	}

	return charge;

}

int main()
{
	double hours1, hours2, hours3;
	double charge1, charge2, charge3;
	double total_hours, total_charges;

	//input from three customers
	cout << "Hours for customer 1: ";
	cin >> hours1;

	cout << "Hours for customer 2: ";
	cin >> hours2;

	cout << "Hours for customer 3: ";
	cin >> hours3;


	//calculations
	charge1 = calculateCharges(hours1);
	charge2 = calculateCharges(hours2);
	charge3 = calculateCharges(hours3);

	//Total hours & charges
	total_hours = hours1 + hours2 + hours3;
	total_charges = charge1 + charge2 + charge3;

	//print table
	cout << fixed << setprecision(2);
	cout << "\nCar\tHours\tCharge" << endl;
	cout << "1\t" << hours1 << "\t" << charge1 << endl;
	cout << "2\t" << hours2 << "\t" << charge2 << endl;
	cout << "3\t" << hours3 << "\t" << charge3 << endl;
	cout << "Total\t" << total_hours << "\t" << total_charges << endl;


	cin.ignore();
	cin.get();

	return 0;
}


//I noticed a bit of discrepency between the result of the test case in my program
//and what is supposed to be output, where in my code it shows the total charges
//as 95.00 instead of the expected 95.50. I'm assuming it's just a typo or something
//as i've revised the code a couple times and this is as simple as i can make it, with it giving me the same answer.