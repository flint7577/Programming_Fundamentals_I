/* Create a class called Date that includes three pieces of information as data members�a month
(type int), a day (type int) and a year (type int). Your class should have a constructor with three
parameters that uses the parameters to initialize the three data members. For the purpose of this
exercise, assume that the values provided for the year and day are correct, but ensure that the
month value is in the range 1�12; if it isn�t, set the month to 1. Provide a set and a get function for
each data member. Provide a member function displayDate that displays the month, day and year
separated by forward slashes (/). Write a test program that demonstrates class Date�s capabilities. */


#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m, int d, int y) {
        if (m >= 1 && m <= 12)
            month = m;
        else
            month = 1;

        day = d;
        year = y;
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12)
            month = m;
        else
            month = 1;
    }

    int getMonth() {
        return month;
    }

    void setDay(int d) {
        day = d;
    }

    int getDay() {
        return day;
    }

    void setYear(int y) {
        year = y;
    }

    int getYear() {
        return year;
    }

    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {

    Date date1(13, 15, 2025); // invalid month, will default to 1
    date1.displayDate();

    date1.setMonth(12);
    date1.setDay(25);
    date1.setYear(2024);

    date1.displayDate();

    return 0;
}
