#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee
{
private:
	struct EmployeeNode
	{
		int employeeNum;
		string firstName;
		string lastName;
		int age;
		EmployeeNode *next;
	};
	EmployeeNode *head;
public:
	Employee()
		{head = nullptr;}
	~Employee();
	void appendNode(int, string, string, int);
	void deleteNode(int);
	void displayList() const;
	void displayCount() const;
	void editEmployee(int, string, string, int);
	int search(int);
};
#endif
