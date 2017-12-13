#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Animal.h"

using namespace std;

void menu();
void printList(const vector <Animal> & aniList);
void add(vector <Animal> & aniList);
int search(const vector <Animal> & aniList, string searchFor);

int main()
{
	vector<Animal> aniList;
	string looperA;
	bool looperB = false;

	while (looperB == false)
	{
		menu();
		cout << "\nEnter choice:" << endl;
		getline(cin, looperA);

		if (looperA == "1")
		{
			printList(aniList);
		}
		else if (looperA == "2")
		{
			add(aniList);
		}
		else if (looperA == "3")
		{
			string searchFor;
			int searchVal;
			cout << "\nEnter animal name: " << endl;
			getline(cin, searchFor);
			searchVal = search(aniList, searchFor);
			if (searchVal == -1)
			{
				cout << "\nERROR: ANIMAL NUMBER NOT FOUND" << endl;
			}
			else
			{
				cout << "\nName: " << aniList[searchVal].getName() << setw(10) << "Age: " << aniList[searchVal].getAge() << endl;
			}
		}
		else if (looperA == "4")
		{
			string searchFor;
			int searchVal;
			cout << "\nEnter animal name that you wish to delete: " << endl;
			getline(cin, searchFor);
			searchVal = search(aniList, searchFor);
			if (searchVal == -1)
			{
				cout << "\nERROR: ANIMAL NUMBER NOT FOUND" << endl;
			}
			else
			{
				aniList.erase(aniList.begin() + searchVal);
				cout << "\nEntry has been deleted" << endl;
			}
		}
		else if (looperA == "5")
		{
			cout << "\n" << "Lab 5a By: Alex Irizarry has ended" << endl;
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
	cout << "\nEnter choice 1 to see a list of animals" << endl;
	cout << "Enter choice 2 to add an animal to the list" << endl;
	cout << "Enter choice 3 to search for an animal by name" << endl;
	cout << "Enter choice 4 to remove an animal from the list" << endl;
	cout << "Enter choice 5 to end the program" << endl;
}

void printList(const vector <Animal> & aniList)
{
	int i = 0;
	int size = aniList.size();

	for (i = 0; i < size; i++)
	{
		cout << "\nInformation for Animal " << (i + 1) << endl;
		cout << "Name: " << aniList[i].getName() << setw(10) << "Age: " << aniList[i].getAge() << endl;
	}
}

void add(vector <Animal> & aniList)
{
	string animalName;
	int animalAge;

	cout << "\nEnter animal name: " << endl;
	getline(cin, animalName);
	cout << "Enter animal age: " << endl;
	cin >> animalAge;
	cin.ignore(1000, '\n');
	

	Animal newAnimal;
	newAnimal.setName(animalName);
	newAnimal.setAge(animalAge);

	aniList.push_back(newAnimal);
}

int search(const vector <Animal> & aniList, string searchFor)
{
	int i = 0;
	int pos = -1;
	bool found = false;
	int numElems = aniList.size();


	while (i < numElems && !found)
	{
		if (aniList[i].getName() == searchFor)
		{
			found = true;
			pos = i;
		}
		i++;
	}
	return pos;
}

void Animal::setName(string n)
{
	name = n;
}

void Animal::setAge(int a)
{
	age = a;
}

string Animal::getName() const
{
	return name;
}

int Animal::getAge() const
{
	return age;
}