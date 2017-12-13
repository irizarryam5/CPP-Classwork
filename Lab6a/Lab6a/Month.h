#ifndef MONTH_H
#define MONTH_H

using namespace std;

class Month
{
private:
	string name;
	int monthNumber;
public:
	Month()
	{
		name = "";
		monthNumber = 0;
	}
	Month(string mname)
	{
		name = mname;
	}
	Month(int mnum)
	{
		monthNumber = mnum;
	}

	void setMonthName(string);
	void setMonthNumber(string);
	string getMonthName() const;
	int getMonthNumber() const;

	// overloaded prefix ++ operator
	Month operator++ ()
	{
		++monthNumber;          
		if (monthNumber >= 12)
		{
			monthNumber = 1;
		}
		return monthNumber;
	}
	// overloaded postfix ++ operator
	Month operator++(int)
	{
		++monthNumber;
		if (monthNumber >= 60)
		{
			monthNumber = 1;
		}
		return monthNumber;
	}

	friend ostream &operator << (ostream &oss, const Month &month)
	{
		return oss << month.monthNumber << month.name;
	}

	friend istream &operator >> (istream &iss, Month &month)
	{
		return iss >> month.monthNumber >> month.name;
	}
};
#endif
