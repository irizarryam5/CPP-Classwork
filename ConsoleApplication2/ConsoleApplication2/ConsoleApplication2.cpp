#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 5;

int main()
{
	string aniNames[SIZE];
	int aniAges[SIZE];
	int count = 0;

	for (count = 0; count < SIZE; count++)
	{
		cout << "Enter animal " << (count + 1) << " name:" << endl;
		getline(cin, aniNames[count]);
		cout << "Enter animal " << (count + 1) << " age:" << endl;
		cin >> aniAges[count];
		cin.ignore(1000, '\n');
	}


	for (count = 0; count < SIZE; count++)
	{
		
		cout << (count + 1) << setw(10) << aniNames[count].length() << setw(15) << aniAges[count] << endl;
			
	}
	system("pause");
	return 0;
}
