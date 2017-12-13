// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <fstream> 
#include <string>
using namespace std;

const string FILEPATH = "C:\\Temp\\inventoryFile.dat";

struct Inventory
{
	int itemNumber;
	char desc[30];
	int qty;
	double wholeSaleCost;
};

// Function prototypes
void addRecord(fstream &datFile);
void viewRecord(fstream &datFile);
void changeRecord(fstream &datFile);

int main()
{
	fstream inventoryFile;
	int choice;
	cout << setprecision(2) << fixed;  
	do 
	{
		// Display the menu.
		cout << "\n1. Add a new record\n";
		cout << "2. View an existing record\n";
		cout << "3. Change an existing record\n";
		cout << "4. Exit\n\n";
		do
		{
			cout << "Enter your choice (1-4): ";
			cin >> choice;
		} while (choice < 1 || choice > 4);
		// Process the selection.
		switch (choice)
		{
		// Choice 1 is to add a record.
		case 1:      
			addRecord(inventoryFile);
			break;    
		// Choice 2 is to view a record.
		case 2:      
			viewRecord(inventoryFile);
			break;
		// Choice 3 is to change a record.
		case 3:      
			changeRecord(inventoryFile);
		}
	} while (choice != 4);
	system ("pause"); 
	return 0;
}

void addRecord(fstream &datFile)
{
	Inventory record;

	datFile.open(FILEPATH, ios::out | ios::app | ios::binary);

	if (datFile.fail())
	{
		cout << "ERROR: FILE DID NOT OPEN" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "\nEnter inventory info:\n";

	cout << "Item #: ";
	cin >> record.itemNumber;
	cin.ignore(1000, '\n');
	while (record.itemNumber < 0)
	{
		cout << "Enter a valid item #: ";
		cin >> record.itemNumber;
		if (cin.fail() || record.itemNumber < 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	cout << "Description: ";
	cin.getline(record.desc, 30);

	cout << "Quantity: ";
	cin >> record.qty;
	cin.ignore(1000, '\n');
	while (record.qty < 0)
	{
		cout << "Enter valid quantity: ";
		cin >> record.qty;
		if (cin.fail() || record.qty <= 0)
		{	
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	cout << "Wholesale cost: ";
	cin >> record.wholeSaleCost;
	cin.ignore(1000, '\n');
	while (record.wholeSaleCost < 0)
	{
		cout << "Enter valid cost: ";
		cin >> record.wholeSaleCost;
		if (cin.fail() || record.wholeSaleCost <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');	
		}
	}

	datFile.write(reinterpret_cast<char *>(&record), sizeof(record));

	if (datFile.fail())
	{
		cout << "ERROR: COULD NOT WRITE TO FILE." << endl;
	}
	else
	{
		cout << "record written to file." << endl;
	}

	datFile.close();
}

void viewRecord(fstream &datFile)
{
	Inventory record;


	int recNum;

	datFile.open(FILEPATH, ios::in | ios::binary);

	if (datFile.fail())
	{
		cout << "ERROR: COULD NOT OPEN FILE." << endl;
		exit(EXIT_FAILURE);
	}

	cout << "\nEnter the record number of the item: ";
	cin >> recNum;

	datFile.seekg(recNum *sizeof(record), ios::beg);
	if (datFile.fail())
	{
		cout << "\nERROR: COULD NOT FIND FILE.\n";
		datFile.close();
		exit(EXIT_FAILURE);
	}

	datFile.read(reinterpret_cast<char *>(&record), sizeof(record));
	datFile.close();

	cout << "Item number: " << record.itemNumber << endl;
	cout << "Description: " << record.desc << endl;
	cout << "Quantity: " << record.qty << endl;
	cout << "Wholesale cost: " << record.wholeSaleCost << endl;
}

void changeRecord(fstream &datFile)
{
	Inventory record;
	int recNum;

	datFile.open(FILEPATH, ios::in | ios::out | ios::binary);

	if (datFile.fail())
	{
		cout << "ERROR COULD NOT OPEN FILE.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter the record number of the item: ";
	cin >> recNum;

	datFile.seekg(recNum *sizeof(record), ios::beg);
	if (datFile.fail())
	{
		cout << "ERROR COULD NOT FIND FILE.\n";
		datFile.close();
		exit(EXIT_FAILURE);
	}

	datFile.read(reinterpret_cast<char *>(&record), sizeof(record));

	cout << "Current record contents: " << endl;
	cout << "Item Number: " << record.itemNumber << endl;
	cout << "Description: " << record.desc << endl;
	cout << "Quantity: " << record.qty << endl;
	cout << "Wholesale cost: " << record.wholeSaleCost << endl;

	cout << "\nEnter the new data: " << endl;
	cout << "\nItem #: ";
	cin >> record.itemNumber;
	cin.ignore(1000, '\n');
	while (record.itemNumber < 0)
	{
		cin >> record.itemNumber;
		if (cin.fail() || record.itemNumber <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Enter a valid item #: ";
		}
	}

	cout << "Description: ";
	cin.getline(record.desc, 30);

	cout << "Quantity: ";
	cin >> record.qty;
	cin.ignore(1000, '\n');
	while (record.qty < 0)
	{
		cout << "Enter valid quantity: ";
		cin >> record.qty;
		if (cin.fail() || record.qty <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	cout << "Wholesale cost: ";
	cin >> record.wholeSaleCost;
	cin.ignore(1000, '\n');
	while (record.wholeSaleCost < 0)
	{
		cout << "Enter valid cost: ";
		cin >> record.wholeSaleCost;
		if (cin.fail() || record.wholeSaleCost <= 0)
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	
	datFile.seekp(recNum *sizeof(record), ios::beg);
	datFile.write(reinterpret_cast<char *>(&record), sizeof(record));
	datFile.close();
}