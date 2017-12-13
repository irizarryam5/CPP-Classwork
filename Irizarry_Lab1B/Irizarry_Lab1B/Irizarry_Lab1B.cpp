//Lab 1B by: Alex Irizarry

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

const int SIZE = 5;

int main()
{
	vector<string> aniNames(SIZE);
	vector<int> aniAges(SIZE);
	int count = 0;

	for (count = 0; count < SIZE; count++)
	{
		cout << "Enter animal " << (count + 1) << " name:" << endl;
		getline(cin, aniNames[count]);
		if (aniNames[count] == "Stop" || aniNames[count] == "STOP" || aniNames[count] == "stop")
		{
			aniNames[count] = " ";
			break;
		}
		else
		{
			cout << "Enter animal " << (count + 1) << " age:" << endl;
			cin >> aniAges[count];
			cin.ignore(1000, '\n');
		}
	}

	cout << '\n' << "Lab 01 By: Alex Irizarry" << endl;
	cout << '\n' << "Animal" << endl;
	cout << "#" << setw(10) << "Name" << setw(15) << "Age" << endl;

	for (count = 0; count < SIZE; count++)
	{
		if (aniNames[count].length() > 1)
			cout << (count + 1) << setw(10) << aniNames[count] << setw(15) << aniAges[count] << endl;
		else
			break;
	}

	system("pause");
	return 0;
}