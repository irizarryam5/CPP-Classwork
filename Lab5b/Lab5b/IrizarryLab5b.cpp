#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Family.h"

using namespace std;

void menu();
void printList(const vector <Family> & famList);
void add(vector <Family> & famList);
int search(const vector <Family> & famList, string searchFor);

int main()
{
	vector<Family> famList;
	string looperA;
	bool looperB = false;

	while (looperB == false)
	{
		menu();
		cout << "\nEnter choice:" << endl;
		getline(cin, looperA);

		if (looperA == "1")
		{
			printList(famList);
		}
		else if (looperA == "2")
		{
			add(famList);
		}
		else if (looperA == "3")
		{
			string searchFor;
			int searchVal;
			int j;
			cout << "\nEnter last name: " << endl;
			getline(cin, searchFor);
			searchVal = search(famList, searchFor);
			if (searchVal == -1)
			{
				cout << "\nERROR: FAMILY NOT FOUND" << endl;
			}
			else
			{
				cout << "\nThe " << famList[searchVal].getFamilyName() << endl;
				cout << "\nParent(s):" << endl;
				for (j = 0; j < 2; j++)
				{
					if (famList[searchVal].getParentsNames(j).length() > 0)
						cout << "Name: " << famList[searchVal].getParentsNames(j) << setw(10) << "Age: " << famList[searchVal].getParentsAges(j) << endl;
				}
				if (famList[searchVal].getChildrensNames(0).length() > 0)
				{
					cout << "\nChildren:" << endl;
					for (j = 0; j < 10; j++)
					{
						if (famList[searchVal].getChildrensNames(j).length() > 0)
							cout << "Name: " << famList[searchVal].getChildrensNames(j) << setw(10) << "Age: " << famList[searchVal].getChildrensAges(j) << endl;
					}
				}
			}
		}
		else if (looperA == "4")
		{
			string searchFor;
			int searchVal;
			cout << "\nEnter family name that you wish to delete: " << endl;
			getline(cin, searchFor);
			searchVal = search(famList, searchFor);
			if (searchVal == -1)
			{
				cout << "\nERROR: FAMILY NOT FOUND" << endl;
			}
			else
			{
				famList.erase(famList.begin() + searchVal);
				cout << "\nEntry has been deleted" << endl;
			}
		}
		else if (looperA == "5")
		{
			cout << "\n" << "Lab 5b By: Alex Irizarry has ended" << endl;
			looperB = true;
		}
		else
		{
			cout << "\nERROR: INVALID SELECTION PLEASE CHOOSE A VALID CHOICE" << endl;
		}
	}
	system("pause");
	return 0;
}

void menu()
{
	cout << "\nEnter choice 1 to see a list families" << endl;
	cout << "Enter choice 2 to add a family to the list" << endl;
	cout << "Enter choice 3 to search for a family by last name" << endl;
	cout << "Enter choice 4 to remove a family from the list" << endl;
	cout << "Enter choice 5 to end the program" << endl;
}

void printList(const vector <Family> & famList)
{
	int i = 0;
	int j = 0;
	int size = famList.size();

	for (i = 0; i < size; i++)
	{
		cout << "\nThe " << famList[i].getFamilyName() << " Family" << endl;
		cout << "\nParent(s):" << endl;
		for(j = 0; j < 2; j++)
		{
			if(famList[i].getParentsNames(j).length() > 0)
				cout << "Name: " << famList[i].getParentsNames(j) << setw(10) << "Age: " << famList[i].getParentsAges(j) << endl;
		}
		if (famList[i].getChildrensNames(0).length() > 0)
		{
			cout << "\nChildren:" << endl;
			for (j = 0; j < 10; j++)
			{
				if (famList[i].getChildrensNames(j).length() > 0)
					cout << "Name: " << famList[i].getChildrensNames(j) << setw(10) << "Age: " << famList[i].getChildrensAges(j) << endl;
			}
		}
	}
}

void add(vector <Family> & famList)
{
	const string order[10] = { "first", "second", "third", "fourth", "fifth",
		"sixth", "seventh", "eighth", "ninth", "tenth" };
	string famName;
	string parName[2];
	string kidName[10];
	int parAge[2];
	int kidAge[10];
	int numParents;
	int numKids;
	bool i = false;
	bool j = false;

	cout << "\nEnter family name: " << endl;
	getline(cin, famName);
	while (i == false)
	{	
		cout << "\nEnter number of parents (1 or 2): " << endl;
		cin >> numParents;
		cin.ignore(1000, '\n');
		if (numParents == 1)
		{
			cout << "\nEnter parent's name: " << endl;
			getline(cin, parName[0]);
			cout << "\nEnter parent's age: " << endl;
			while (parAge[0] < 0)
			{
				cin >> parAge[0];
				cin.ignore(1000, '\n');
				if (cin.fail() || parAge[0] <= 0)
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\nEnter valid age: " << endl;
				}
			}
			i = true;
		}
		else if (numParents == 2)
		{
			cout << "\nEnter first parent's name: " << endl;
			getline(cin, parName[0]);
			cout << "\nEnter first parent's age: " << endl;
			while (parAge[0] < 0)
			{
				cin >> parAge[0];
				cin.ignore(1000, '\n');
				if (cin.fail() || parAge[0] <= 0)
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\nEnter valid age: " << endl;
				}
			}
			cout << "\nEnter second parent's name: " << endl;
			getline(cin, parName[1]);
			cout << "\nEnter second parent's age: " << endl;
			while (parAge[1] < 0)
			{
				cin >> parAge[1];
				cin.ignore(1000, '\n');
				if (cin.fail() || parAge[1] <= 0)
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\nEnter valid age: " << endl;
				}
			}
			i = true;
		}
		else
		{
			cout << "\nERROR: ENTER A VALID NUMBER OF PARENTS\n";
			i = false;
		}
	}

	while (j == false)
	{
		cout << "\nEnter number of children (0 through 10): " << endl;
		cin >> numKids;
		cin.ignore(1000, '\n');
		if (numKids == 0)
		{
			j = true;
		}
		else if (numKids >= 1 && numKids <= 10)
		{
			int x;
			for (x = 0; x < numKids; x++)
			{
				cout << "\nEnter " << order[x] << " child's name: " << endl;
				getline(cin, kidName[x]);
				cout << "\nEnter " << order[x] << " child's age: " << endl;
				while (kidAge[x] < 0)
				{
					cin >> kidAge[x];
					cin.ignore(1000, '\n');
					if (cin.fail() || kidAge[x] <= 0)
					{
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "\nEnter valid age: " << endl;
					}
				}
			}
			j = true;
		}
		else
		{
			j = false;
			cout << "\nERROR: ENTER A VALID NUMBER OF CHILDREN\n";
		}
	}

	Family newFam;
	newFam.setFamilyName(famName);
	newFam.setParents(parName, parAge);
	newFam.setChildren(kidName, kidAge);

	famList.push_back(newFam);
}

int search(const vector <Family> & famList, string searchFor)
{
	int i = 0;
	int pos = -1;
	bool found = false;
	int numElems = famList.size();


	while (i < numElems && !found)
	{
		if (famList[i].getFamilyName() == searchFor)
		{
			found = true;
			pos = i;
		}
		i++;
	}
	return pos;
}

void Family::setFamilyName(string n)
{
	familyName = n;
}

void Family::setParents(string n[2], int a[2])
{
	int i;

	for (i = 0; i < 2; i++)
	{
		parents[i].firstName = n[i];
		parents[i].age = a[i];
	}
}

void Family::setChildren(string n[10], int a[10])
{
	int i;

	for (i = 0; i < 10; i++)
	{
		children[i].firstName = n[i];
		children[i].age = a[i];
	}
}

string Family::getFamilyName() const
{
	return familyName;
}

string Family::getParentsNames(int i) const
{
	return parents[i].firstName;
}

int Family::getParentsAges(int i) const
{
	return parents[i].age;
}

string Family::getChildrensNames(int i) const
{
	return children[i].firstName;
}

int Family::getChildrensAges(int i) const
{
	return children[i].age;
}
