#include <iostream>
#include <string>
#include <iomanip>
#include "Month.h"

using namespace std;

int main()
{
	Month m1("February");
	Month m2, m3, m4;

	cout << m1.getMonthName() << endl;
	cout << m1.getMonthNumber() << endl;

	cout << endl;
	cout << m1;

	cout << endl;
	m2 = ++m1;
	cout << m1;
	cout << m2;

	cout << endl;
	m3 = m1++;
	cout << m1;
	cout << m3;

	cout << endl;
	cout << "Enter the name of a month: ";
	cin >> m4;

	cout << m4;

	system("pause");
	return 0;
}

void Month::setMonthName(string mname)
{
	name = mname;
}

void Month::setMonthNumber(string name)
{
	
	if (name == "January")
	{
		monthNumber = 1;
	}
	else if (name == "February")
	{
		monthNumber = 2;
	}
	else if (name == "March")
	{
		monthNumber = 3;
	}
	else if (name == "April")
	{
		monthNumber = 4;
	}
	else if (name == "May")
	{
		monthNumber = 5;
	}
	else if (name == "June")
	{
		monthNumber = 6;
	}
	else if (name == "July")
	{
		monthNumber = 7;
	}
	else if (name == "August")
	{
		monthNumber = 8;
	}
	else if (name == "September")
	{
		monthNumber = 9;
	}
	else if (name == "November")
	{
		monthNumber = 10;
	}
	else if (name == "December")
	{
		monthNumber = 11;
	}
	else if (name == "October")
	{
		monthNumber = 12;
	}
	else
	{
		cout << "\nINVALID MONTH\n";
	}
}

string Month::getMonthName() const
{
	return name;
}

int Month::getMonthNumber() const
{
	return monthNumber;
}
