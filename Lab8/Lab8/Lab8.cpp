#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"

using namespace std;

void menu();

int Employee::search(int searchFor)
{
	int i = 0;
	int pos = -1;
	bool found = false;

	EmployeeNode *nodeptr;
	nodeptr = head;

	while (nodeptr && !found)
	{
		if (nodeptr->employeeNum == searchFor)
		{
			found = true;
			pos = i;
		}
		nodeptr = nodeptr->next;
		i++;
	}
	return pos;
}

void Employee::appendNode(int employeeNum, string firstName, string lastName, int age)
{
	EmployeeNode *nodeptr;
	EmployeeNode *newNode;

	newNode = new EmployeeNode;
	newNode->employeeNum = employeeNum;
	newNode->firstName = firstName;
	newNode->lastName = lastName;
	newNode->age = age;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodeptr = head;
		while (nodeptr->next)
			nodeptr = nodeptr->next;
		nodeptr->next = newNode;
	}
}

void Employee::deleteNode(int num)
{
	EmployeeNode *nodeptr;
	EmployeeNode *previousnode;

	if (!head)
		return;
	if (head->employeeNum == num)
	{
		nodeptr = head->next;
		delete head;
		head = nodeptr;
	}
	else
	{
		nodeptr = head;
		while ((nodeptr != nullptr) && (nodeptr->employeeNum != num))
		{
			previousnode = nodeptr;
			nodeptr = nodeptr->next;
		}

		if (nodeptr)
		{
			previousnode->next = nodeptr->next;
			delete nodeptr;
		}
	}
}

void Employee::displayList() const
{
	EmployeeNode *nodeptr;

	nodeptr = head;

	while (nodeptr)
	{
		cout << "Employee number: " << nodeptr->employeeNum << endl;
		cout << "First name: " << nodeptr->firstName << endl;
		cout << "Last name: " << nodeptr->lastName << endl;
		cout << "Age: " << nodeptr->age << endl << endl;

		nodeptr = nodeptr->next;
	}
}

void Employee::displayCount() const
{
	EmployeeNode *nodeptr;
	int count = 0;
	nodeptr = head;

	while (nodeptr)
	{
		count++;
		nodeptr = nodeptr->next;
	}

	cout << "\nAlex Irizarry has a linked list with " << count << " entries." << endl;
}

void Employee::editEmployee(int employeeNum, string firstName, string lastName, int age)
{
	EmployeeNode *nodeptr;
	EmployeeNode *previousNode;

	if (!head)
		return;
	if (head->employeeNum == employeeNum)
	{
		nodeptr = head->next;

		nodeptr->employeeNum = employeeNum;
		nodeptr->firstName = firstName;
		nodeptr->lastName = lastName;
		nodeptr->age = age;
		nodeptr->next = nullptr;
		head = nodeptr;
	}
	else
	{
		nodeptr = head;
		while (nodeptr != nullptr && nodeptr->employeeNum != employeeNum)
		{
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}
	
		if (nodeptr)
		{
		previousNode->next = nodeptr->next;
		nodeptr->employeeNum = employeeNum;
		nodeptr->firstName = firstName;
		nodeptr->lastName = lastName;
		nodeptr->age = age;
		}
		
	}
}

Employee::~Employee()
{
	EmployeeNode *nodeptr;
	EmployeeNode *nextNode;

	nodeptr = head;

	while (nodeptr != nullptr)
	{
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}
}

int main()
{
	Employee empList;
	string looperA;
	bool looperB = false;

	while (looperB == false)
	{
		menu();
		cout << "\nEnter choice:" << endl;
		getline(cin, looperA);

		if (looperA == "1")
		{
			empList.displayList();
		}
		else if (looperA == "2")
		{
			int id;
			string fname;
			string lname;
			int age;

			cout << "\nEnter employee number: ";
			cin >> id;
			cin.ignore(1000, '\n');
			cout << "\nEnter employee first name: ";
			getline(cin, fname);
			cout << "\nEnter employee last name: ";
			getline(cin, lname);
			cout << "\nEnter employee age: ";
			cin >> age;
			cin.ignore(1000, '\n');

			empList.appendNode(id, fname, lname, age);
		}
		else if (looperA == "3")
		{
			int searchFor;
			int searchVal;

			cout << "\nEnter Employee Number: " << endl;
			cin >> searchFor;
			cin.ignore(1000, '\n');

			searchVal = empList.search(searchFor);
			if (searchVal == -1)
			{
				cout << "\nERROR: EMPLOYEE NOT FOUND" << endl;
			}
			else
			{
				int id;
				string fname;
				string lname;
				int age;

				cout << "\nEnter employee number: ";
				cin >> id;
				cin.ignore(1000, '\n');
				cout << "\nEnter employee first name: ";
				getline(cin, fname);
				cout << "\nEnter employee last name: ";
				getline(cin, lname);
				cout << "\nEnter employee age: ";
				cin >> age;
				cin.ignore(1000, '\n');

				empList.editEmployee(id, fname, lname, age);
			}
		}
		else if (looperA == "4")
		{
			int searchFor;
			int searchVal;
			cout << "\nEnter employee number that you wish to delete: " << endl;
			cin >> searchFor;
			cin.ignore(1000, '\n');

			searchVal = empList.search(searchFor);
			if (searchVal == -1)
			{
				cout << "\nERROR: EMPLOYEE NOT FOUND" << endl;
			}
			else
			{
				empList.deleteNode(searchFor);
				cout << "\nEntry has been deleted" << endl;
			}
		}
		else if(looperA == "5")
		{
			empList.displayCount();
		}
		else if (looperA == "6")
		{
			cout << "\n" << "Lab 8 By: Alex Irizarry has ended" << endl;
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
	cout << "\nEnter choice 1 to see a list employees" << endl;
	cout << "Enter choice 2 to add an employee to the list" << endl;
	cout << "Enter choice 3 to change an employee's info" << endl;
	cout << "Enter choice 4 to remove an employee from the list" << endl;
	cout << "Enter choice 5 to see a number of employees" << endl;
	cout << "Enter choice 6 to end the program" << endl;
}


